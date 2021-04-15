$ cc header.c
$ cc meshhotfix.c
$ cc regularhotfix.c
$ cc tablehotfix.c
$ cc utilgame.c
$ cc utilunique.c
$ lib/create libbl3mod.lib header,meshhotfix,regularhotfix,tablehotfix,utilgame,utilunique