// ProgressBox.h

#ifndef __PROGRESSBOX_H
#define __PROGRESSBOX_H

#include "Common/MyString.h"
#include "Common/Types.h"

#ifdef _UNICODE
void ConvertUInt64ToStringAligned(UInt64 value, wchar_t *s, int alignSize);
#else
void ConvertUInt64ToStringAligned(UInt64 value, char *s, int alignSize);
#endif

class CMessageBox
{
  CSysString _title;
  int _width;
public:
  void Init(const CSysString &title, int width);
	CSysString GetTitle();
#ifdef _UNICODE
	void ShowMessages(const wchar_t *strings[], int numStrings);
#else
	void ShowMessages(const char *strings[], int numStrings);
#endif
};

class CProgressBox: public CMessageBox
{
  CSysString _prevMessage;
  CSysString _prevPercentMessage;
  bool _wasShown;
public:
  void Init(const CSysString &title, int width);
  void Progress(const UInt64 *total, const UInt64 *completed, const CSysString &message);
};

#endif
