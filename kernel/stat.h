#define T_DIR 1	   // Directory
#define T_FILE 2   // File
#define T_DEVICE 3 // Device

// when calling the sys call "fstat", the info of the inode will be presented as a stat
struct stat
{
	int dev;	 // File system's disk device
	uint ino;	 // Inode number
	short type;	 // Type of file
	short nlink; // Number of links to file
	uint64 size; // Size of file in bytes
};
