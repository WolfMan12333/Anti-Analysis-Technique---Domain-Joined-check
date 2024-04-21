Anti-Analysis: Domain Joined Check - Diving into a function inside of the Netapi32.dll library known as
	NetGetJoinInformation. NetGetJoinInformation is used to determine the join status of a computer.
	There will be occasions where the sandbox machine on the network, or in the cloud will NOT be a domain
	joined machine. This is a very strong Anti-Analysis feature that is used by many open source and
	commercial C&Cs. The program should check the join status of the machine with the NetSetupDomainName
	enumeration, and continue execution if it is confirmed to be domain joined.


Treat this as template of this anti-analysis technique. You already know in main where to put inject part