#ifndef IMAPHANDLER_H
#define IMAPHANDLER_H

class IMap;

class IMapHandler
{
	public:
		virtual IMap &map() = 0;
};

#endif // IMAPHANDLER_H
