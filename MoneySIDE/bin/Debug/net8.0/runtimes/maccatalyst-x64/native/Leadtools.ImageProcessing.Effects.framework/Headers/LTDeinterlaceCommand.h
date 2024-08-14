// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDeinterlaceCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTDeinterlaceCommandFlags) {
    LTDeinterlaceCommandFlagsNone   = 0x0000,
    LTDeinterlaceCommandFlagsNormal = 0x0001,
    LTDeinterlaceCommandFlagsSmooth = 0x0002,
    LTDeinterlaceCommandFlagsOdd    = 0x0010,
    LTDeinterlaceCommandFlagsEven   = 0x0020
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDeinterlaceCommand : LTRasterCommand

@property (nonatomic, assign) LTDeinterlaceCommandFlags flags;

- (instancetype)initWithFlags:(LTDeinterlaceCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
