// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTEmbossCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTEmbossCommandDirection) {
    LTEmbossCommandDirectionNorth     = 0x0000,
    LTEmbossCommandDirectionNorthEast = 0x0001,
    LTEmbossCommandDirectionEast      = 0x0002,
    LTEmbossCommandDirectionSouthEast = 0x0003,
    LTEmbossCommandDirectionSouth     = 0x0004,
    LTEmbossCommandDirectionSouthWest = 0x0005,
    LTEmbossCommandDirectionWest      = 0x0006,
    LTEmbossCommandDirectionNorthWest = 0x0007
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTEmbossCommand : LTRasterCommand

@property (nonatomic, assign) LTEmbossCommandDirection direction;
@property (nonatomic, assign) NSUInteger depth;

- (instancetype)initWithDirection:(LTEmbossCommandDirection)direction depth:(NSUInteger)depth NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
