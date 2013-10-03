#!/bin/sh

echo "/* -- block generated by $0 */"

echo "document				: /* empty */"

for i in $(grep OPEN tokens.txt)
do
	echo "			| document "$i" document "gap_$(echo $i | sed 's/_OPEN//' | tr '[:upper:]' '[:lower:]' )"										{ if ( DEBUG_LEVEL != 0) printf("'"reduce document '$i'\\n"'"); }"
done

#echo "			| document error token									{ if ( DEBUG_LEVEL != 0 ) printf("'"%s -> reduce document ERROR\\n"'", linebuf); errors++; yyerrok; }"
echo "			;"
echo "/* -- end of block */"