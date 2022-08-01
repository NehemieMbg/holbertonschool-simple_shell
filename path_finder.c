#include "main.h"

/**
 *
 *
 */

char *pathfinder(char *cmd, char *PATH)
{
	char *p_item = NULL;
	char *fullpath = NULL;
	/**
	 *if (access(cmd, X_OK) == 0)
	 *	return (cmd);
	 */
	p_item = strtok(PATH, ":");
	while (p_item)
	{
		fullpath = malloc(sizeof(char) * (strlen(cmd) + strlen(p_item)) + 2);
		fullpath = strcpy(fullpath, p_item);
		fullpath = strcat(fullpath, "/");
		fullpath = strcat(fullpath, cmd);
		if (access(fullpath, X_OK) == 0)
			return (fullpath);
		free(fullpath);
		fullpath = NULL;
		p_item = strtok(NULL, ":");
	}
	return (strdup(cmd));
}
