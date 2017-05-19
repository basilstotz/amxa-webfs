#
# Regular cron jobs for the amxa-webfs package
#
0 4	* * *	root	[ -x /usr/bin/amxa-webfs_maintenance ] && /usr/bin/amxa-webfs_maintenance
