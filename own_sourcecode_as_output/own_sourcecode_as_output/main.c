//
//  main.c
//  own_sourcecode_as_output
//
//  Created by Neeraj Kumbhar on 3/22/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

char*s="char*s=%c%s%c;main(){printf(s,34,s,34);}";

main()
{
    printf(s,34,s,34);

}