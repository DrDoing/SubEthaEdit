/*
 * Name: OGReplaceExpressionPrivate.m
 * Project: OgreKit
 *
 * Creation Date: Sep 23 2003
 * Author: Isao Sonobe <sonobe@gauge.scphys.kyoto-u.ac.jp>
 * Copyright: Copyright (c) 2003 Isao Sonobe, All rights reserved.
 * License: OgreKit License
 *
 * Encoding: UTF8
 * Tabsize: 4
 */

#import <OgreKit/OGReplaceExpression.h>
#import <OgreKit/OGReplaceExpressionPrivate.h>


@implementation OGReplaceExpression (Private)

- (void)_setCompiledReplaceString:(NSArray*)compiledReplaceString
{
	_compiledReplaceString = [compiledReplaceString retain];
}

- (void)_setNameArray:(NSArray*)nameArray
{
	_nameArray = [nameArray retain];
}

@end

