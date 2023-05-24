SOURCE = data.txt
TARGET = count.txt

all: $(TARGET)

# $@ : $<    -
# $< matches the source file name $(SOURCE)
# $@ matches the target file name $(TARGET)
$(TARGET): $(SOURCE)
	wc -c $< > $@ #counts characters
	wc -w $< >> $@ #counts words
	wc -l $< >> $@ #counts line

clean:
	rm $(TARGET) #clean this file again


#Automatic Variables
#
#There are some special variables called automatic variables. Their values are computed
#each time for every rule and are based on the target and prerequisite file names.
#Here are some of the most important automatic variables:
#
#    $@	:	This is the TARGET file name. If there is more than one target, this is
#			whichever target caused the recipe to run.
#    $*	:	This is the target file name without the extension.
#    $<	:	This is the name of the first prerequisite.
#    $?	:	The names of all the prerequisites that are newer than the target, with
#			spaces between them. If the target does not exist, all prerequisites will be
#			included.
#    $^	:	The names of all the prerequisites, with spaces between them and duplicates removed.
#    $+	:	Same as $^, except it includes duplicates.
#
#There are other automatic variables. For a full list, see the manual.