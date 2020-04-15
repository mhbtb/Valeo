
#define MAX_FILE_LENGTH 13
#ifndef VCAST_INPUT_DATA_ARRAY_ATTRIBUTE
#define VCAST_INPUT_DATA_ARRAY_ATTRIBUTE
#endif
#ifndef VCAST_STDIN_DATA_SIZE_T 
#define VCAST_STDIN_DATA_SIZE_T unsigned short
#endif 
struct FileData {
	char    name[MAX_FILE_LENGTH]; 
	VCAST_STDIN_DATA_SIZE_T   offset; 
	VCAST_STDIN_DATA_SIZE_T   len; 
}; 
#ifdef __cplusplus
extern "C"
#endif
const struct FileData inputDataArrayTOC[] = {
{{'C','O','M','M','A','N','D','L','.','D','A','T',0},0,31,},
{{'H','A','R','N','O','P','T','S','.','D','A','T',0},31,94}};
#ifdef __cplusplus
extern "C"
#endif
const int isTwoByteLen = 0;
#ifdef __cplusplus
extern "C"
#endif
const int NumInputFiles = 2;
#ifdef __cplusplus
extern "C"
#endif
const char* const VCAST_INPUT_DATA_ARRAY_ATTRIBUTE inputDataArray = 
"\023*FILE:COMMANDL.DAT\012"
"\0121.1.0.0%0\012"
"\023*FILE:HARNOPTS.DAT\012"
"\0120.0.1.4%0\012"
"\0130.0.11.4%3\012"
"\0120.0.2.4%0\012"
"\0120.0.3.4%0\012"
"\0130.0.12.4%0\012"
"\0120.0.0.5%1\012"
"\005*END\012"
;
