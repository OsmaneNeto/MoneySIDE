// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOffsetCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

typedef NS_ENUM(NSInteger, LTOffsetCommandType) {
    LTOffsetCommandTypeColor      = 0x0000,
    LTOffsetCommandTypeRepeat     = 0x0001,
    LTOffsetCommandTypeNoChange   = 0x0002,
    LTOffsetCommandTypeWrapAround = 0x0003
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOffsetCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger horizontalShift;
@property (nonatomic, assign) NSInteger verticalShift;
@property (nonatomic, copy)   LTRasterColor *backColor;
@property (nonatomic, assign) LTOffsetCommandType type;

- (instancetype)initWithHorizontalShift:(NSInteger)horizontalShift verticalShift:(NSInteger)verticalShift backColor:(LTRasterColor *)backColor type:(LTOffsetCommandType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
