#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

struct passwd *
getpwnam(const char *name)
{
    struct passwd  *ptr;

    setpwent();
    while ((ptr = getpwent()) != NULL)
        if (strcmp(name, ptr->pw_name) == 0)
            break;		/* found a match */
    endpwent();
    return(ptr);	/* ptr is NULL if no match found */
}

int
main(int argc, char *argv[])
{
	if(argc != 2)
		printf("Usage: %s user_name", argv[0]);
	else{
		struct passwd  *ptr = NULL;
		if((ptr = getpwnam(argv[1])))
			printf("success, find user %s in /etc/passwd file.\n", argv[1]);
		else
			printf("fail, not find user %s in /etc/passwd file.\n", argv[1]);
	}
	return 0;
}
