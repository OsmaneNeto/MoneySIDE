// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSwapColorsCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTSwapColorsCommandType) {
    LTSwapColorsCommandTypeRedGreen        = 0x0001,
    LTSwapColorsCommandTypeRedBlue         = 0x0002,
    LTSwapColorsCommandTypeGreenBlue       = 0x0004,
    LTSwapColorsCommandTypeRedGreenBlueRed = 0x0008,
    LTSwapColorsCommandTypeRedBlueGreenRed = 0x0010
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSwapColorsCommand : LTRasterCommand

@property (nonatomic, assign) LTSwapColorsCommandType type;

- (instancetype)initWithType:(LTSwapColorsCommandType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
