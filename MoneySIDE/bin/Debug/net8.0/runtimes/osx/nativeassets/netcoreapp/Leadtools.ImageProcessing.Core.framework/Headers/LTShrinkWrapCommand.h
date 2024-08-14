// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTShrinkWrapCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

typedef NS_ENUM(NSUInteger, LTShrinkWrapFlags) {
    LTShrinkWrapFlagsRgnAnd            = 0,
    LTShrinkWrapFlagsRgnSet            = 1,
    LTShrinkWrapFlagsRgnAndNotBitmap   = 2,
    LTShrinkWrapFlagsRgnAndNotRgn      = 3,
    LTShrinkWrapFlagsRgnOr             = 4,
    LTShrinkWrapFlagsRgnXOr            = 5,
    LTShrinkWrapFlagsRgnSetNot         = 6,
    LTShrinkWrapFlagsShrinkRect        = 0x0008,
    LTShrinkWrapFlagsShrinkCircle      = 0x0010
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTShrinkWrapCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger threshold;
@property (nonatomic, assign) NSInteger radius;
@property (nonatomic, assign) LeadPoint center;
@property (nonatomic, assign) LTShrinkWrapFlags flags;

- (instancetype)initWithThreshold:(NSInteger)threshold center:(LeadPoint)center radius:(NSInteger)radius flags:(LTShrinkWrapFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
