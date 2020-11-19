#include "headers.h"

bool isDesktopAvailable()
{
	HDESK desktop = OpenDesktop(TEXT("Default"), 0, false, DESKTOP_SWITCHDESKTOP);
	if (desktop)
	{
		if (SwitchDesktop(desktop))
		{
			CloseDesktop(desktop);
			return true;
		}
		else
		{
			CloseDesktop(desktop);
		}
	}

	return false;
}
