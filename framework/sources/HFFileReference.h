//
//  HFFileReference.h
//  HexFiend_2
//
//  Created by Peter Ammon on 1/23/08.
//  Copyright 2008 ridiculous_fish. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface HFFileReference : NSObject {
    int fileDescriptor;
    dev_t device;
    unsigned long long fileLength;
    unsigned long long inode;
    BOOL isWritable;
}

- initWritableWithPath:(NSString *)path;
- initWithPath:(NSString *)path;
- (void)close;

- (void)readBytes:(unsigned char *)buff length:(NSUInteger)length from:(unsigned long long)pos;
- (int)writeBytes:(unsigned char *)buff length:(NSUInteger)length to:(unsigned long long)offset;

- (unsigned long long)length;

/* Changes the length via ftruncate; returns errno. */
- (int)setLength:(unsigned long long)length;

@end
