#define _GNU_SOURCE

#include <dlfcn.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static struct passwd *(*getpwuid_)(uid_t) = NULL;

struct passwd *getpwuid(uid_t uid)
{
        static struct passwd pwd = {0};
        struct passwd *res;
        char *home;

        if (!getpwuid_) {
                getpwuid_ = dlsym(RTLD_NEXT, __func__);
                if (!getpwuid_)
                        return NULL;
        }

        res = getpwuid_(uid);
        if (!res || uid != getuid())
                return res;
        if (!pwd.pw_dir || pwd.pw_uid != uid) {
                free(pwd.pw_dir);
                pwd.pw_dir = getenv("HOME");
                if (!pwd.pw_dir)
                        return res;
                pwd.pw_dir = strdup(pwd.pw_dir);
                if (!pwd.pw_dir)
                        return res;
        }
        home = pwd.pw_dir;
        pwd = *res;
        pwd.pw_dir = home;
        return &pwd;
}
