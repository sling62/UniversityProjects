/*
 * Author: Samantha Ling
 * Student number: 160720604
 */
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "fileinflib.h"
#include <libgen.h>
#include <sys/param.h>
#include <string.h> 

/* is_user_exec helper function forward declaration */
bool is_user_exec(mode_t mode, uid_t owner_uid, gid_t owner_gid);

/***************************************************************************/
/***** FILEINFLIB.H IMPLEMENTATIONS ****************************************/
/***************************************************************************/
 
/* mode2str function convert's the given file mode bits to a dynamically allocated string
 * representation that is similar in form to the output from the Unix ls command
 */
char *mode2str(mode_t mode, uid_t owner_uid, gid_t owner_gid) { 
    /*type stores the file type bits of the mode when it & with the value of S_IFMT */
    mode_t type = mode & S_IFMT;
	
	/* check to see if the mode is out of bounds */
    if(mode < MODE_MIN || mode > MODE_MAX)
    {
		/*if mode is out of bounds then errno is set to EDOM and the function returns NULL and exits*/
		errno = EDOM;
		return NULL;
    }
	/* check to see if file type & S_IFIFO(check for odd file type bits) is true as well as checking for type not being S_IFIFO */
    if((type & S_IFIFO) && (type != S_IFIFO))
    {
		/*if so then incorrect file type input and errno is set to EDOM and returns NULL to exit out of function */
        errno = EDOM;
        return NULL;
    }
    
	/*dynamically allocating a mode string called modestr which will store the string representation of the file */
	char *modestr = (char*) calloc(MODE_S_LEN,sizeof(char));
	
	/*checking to see if modestr is NULL*/
    if(modestr == NULL) 
    {
		/*if so then errno is set to ENOMEM and returns NULL to exit out of function */
        errno = ENOMEM;
        return NULL;
    }
      
    /*checking permission bits for user, group and other seeing if mode & with the exact value of file mode bits is true 
	*then replace index in modestr with 'r','w' or 'x', however if false then replace index in modestr with '-'
	*/
	modestr[1] = (mode & S_IRUSR) ? 'r' : '-';
	modestr[2] = (mode & S_IWUSR) ? 'w' : '-';
    modestr[3] = (mode & S_IXUSR) ? 'x' : '-';
    modestr[4] = (mode & S_IRGRP) ? 'r' : '-';
	modestr[5] = (mode & S_IWGRP) ? 'w' : '-';
    modestr[6] = (mode & S_IXGRP) ? 'x' : '-';
    modestr[7] = (mode & S_IROTH) ? 'r' : '-';
	modestr[8] = (mode & S_IWOTH) ? 'w' : '-';
    modestr[9] = (mode & S_IXOTH) ? 'x' : '-';
    modestr[10] = '\0';

	/*checking file type bits with type seeing if type & with the exact value of file type bits is true 
	*then replace index of file type in modestr with 'd','e','f','l' or 'o'
	*/
	if(type == S_IFDIR)
	{
		modestr[0] = 'd';
	}
    else if((type == S_IFREG) && (is_user_exec(mode, owner_uid, owner_gid)))
    {
        modestr[0] = 'e';
    }
    else if(type == S_IFREG)
    {
        modestr[0] = 'f';
    }
    else if(type == S_IFLNK)
    {
        modestr[0] = 'l';
    }
	else
	{
        modestr[0] = 'o'; 
    }
    
	/*returns modestr*/
	return modestr;
}

/* see getfileinf specification comments in fileinflib.h */
fileinf *getfileinf(char *path) {
	/*check to see if the size of the path is greater than MAXPATHLEN*/
    if(sizeof(path)>MAXPATHLEN) 
    {
		/*if the size of the path provided is greater than the MAXPATHLEN then errno is set to EINVAL and returns NULL to exit out of function */
		errno = EINVAL;
		return NULL;
    }
    else if(path == NULL)
    {
		/*check to see if path is NULL, if it is then errno is set to ENOMEM and returns NULL to exit out of function */
		errno = ENOMEM;
		return NULL;
    }
    
	/*dynamically allocating a fileinf struct called file*/
    fileinf *file = (fileinf*) malloc(sizeof(fileinf));

	/*check to see if file is NULL, if it is then file is deallocated and errno is set to ENOMEM and returns NULL to exit out of function */
    if(file==NULL)
    {
		free(file);
		errno = ENOMEM;
		return NULL;
    }
 
    /*dynamically allocating a stat struct called filestat*/
    struct stat *filestat = (struct stat*)malloc(sizeof(struct stat));
	/*calling stat function and passing information from path to the dynamically allocated stat struct filestat */
    stat(path, filestat);
    
	/*check to see if filestat is NULL, if it is then filestat is deallocated and errno is set to ENOMEM and returns NULL to exit out of function */
    if(filestat == NULL)
    {
		free(filestat);
		errno = ENOMEM;
		return NULL;
	}
	
    /*fields in file struct like size and mode_s are set to the fields pointed to in filestat*/
	file ->size = filestat -> st_size;
	/*sets mode_s to mode string returned from mode2str*/
    file ->mode_s = mode2str(filestat -> st_mode, filestat -> st_uid, filestat -> st_gid); 
    
	/*pointers are created called dirname1 and basename1 to point to the directory name and base name provided by path*/
    char *dirname1=dirname(path);
    char *basename1 =basename(path);
	
	/*dynamically allocating dirname and basename in file*/
	file -> dirname = (char*) calloc((strlen(dirname1) +1), sizeof(char)); 
    file -> basename= (char*) calloc((strlen(basename1) +1), sizeof(char));
	
	/*check to see if either dirname or basename are NULL, if either are NULL deallocate dirname or basename
	 *and errno is set to ENOMEM and returns NULL to exit out of function
	*/
    if(dirname == NULL)
    {
        free(dirname);
        errno = ENOMEM;
        return NULL;
    }
                
	if(basename == NULL)
    {
        free(basename);
        errno = ENOMEM;
        return NULL;
    }
	
	/*dirname1 and basename1 value is copied to the dirname and basename fields in file and set*/
    file -> dirname = strcpy(file -> dirname, dirname1);
    file -> basename = strcpy(file -> basename, basename1); 

	/*type field in file is set to the charecter value(integer) of the type obtained from mode_s string minus the charecter value of d (integer)*/
    file -> type = file->mode_s[0] - 'd';

   	return file;
}

/* delfileinf function deallocates the memory pointed to by the fileinf struct pointer fi */
void delfileinf(fileinf *fi) {
	/*check to see if fi is not NULL, if it is NULL then fi does not need to be freed*/
	if(fi != NULL)
	{
		/*if fi is not NULL then check to see if mode_s, dirname and basename in fileinf struct is NULL as well
		* if it is then free mode_s, dirname and basename in fileinf struct, otherwise do nothing
		*/
		if((fi -> mode_s) != NULL)
		{
			free(fi -> mode_s);
		}
		if((fi -> dirname) != NULL)
		{
			free(fi -> dirname);
		}
		if((fi -> basename) != NULL)
		{
			free(fi -> basename);
		}
	/*free fileinf struct pointed at by fi*/
    free(fi);
	}
}

/***************************************************************************/
/***** HELPER FUNCTIONS ****************************************************/
/***************************************************************************/

/* 
 * is_user_exec helper function to test user execute permission for given 
 * file mode and file owner uid and file owner gid.
 * Uses getuid() to get the uid of the calling process and getgid() to get the 
 * gid of the calling process.
 * This function is not part of the filecmdrlib interface.
 */ 
bool is_user_exec(mode_t mode, uid_t owner_uid, gid_t owner_gid) {
    if (owner_uid == getuid())
        return mode & S_IXUSR;
    
    if (owner_gid == getgid())
        return mode & S_IXGRP;
        
    return mode & S_IXOTH;
}

/***************************************************************************/
