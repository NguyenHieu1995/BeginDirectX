#ifndef __CMACRO_H__
#define __CMACRO_H__

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) {if(p) {delete(p); (p)=NULL;}}
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p) {if(p) {(p)->Release(); (p)=NULL;}}
#endif

#endif