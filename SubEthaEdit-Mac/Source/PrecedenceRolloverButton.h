//  PrecedenceRolloverButton.h
//  SubEthaEdit
//
//  Created by Martin Pittenauer on 01.10.07.

#import <Cocoa/Cocoa.h>


@interface PrecedenceRolloverButton : NSButton {
	NSTrackingRectTag	trackingTag;
	NSImage				*TCM_altImage;
	BOOL mouseIsIn;	
}

@end
