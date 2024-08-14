// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTResizeInterpolateCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTResizeInterpolateCommandType) {
    LTResizeInterpolateCommandTypeNormal           = 0x0000,
    LTResizeInterpolateCommandTypeResample         = 0x0002,
    LTResizeInterpolateCommandTypeBicubic          = 0x0004,
    LTResizeInterpolateCommandTypeTriangle         = 0x0005,
    LTResizeInterpolateCommandTypeHermite          = 0x0006,
    LTResizeInterpolateCommandTypeBell             = 0x0007,
    LTResizeInterpolateCommandTypeQuadraticBSpline = 0x0008,
    LTResizeInterpolateCommandTypeCubicBSpline     = 0x0009,
    LTResizeInterpolateCommandTypeBoxFilter        = 0x000A,
    LTResizeInterpolateCommandTypeLanczos          = 0x000B,
    LTResizeInterpolateCommandTypeMichell          = 0x000C,
    LTResizeInterpolateCommandTypeCosine           = 0x000D,
    LTResizeInterpolateCommandTypeCatrom           = 0x000E,
    LTResizeInterpolateCommandTypeQuadratic        = 0x000F,
    LTResizeInterpolateCommandTypeCubicConvolution = 0x0010,
    LTResizeInterpolateCommandTypeBilinear         = 0x0011,
    LTResizeInterpolateCommandTypeBresenham        = 0x0012,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTResizeInterpolateCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) LTResizeInterpolateCommandType resizeType;

- (instancetype)initWithWidth:(NSInteger)width height:(NSInteger)height type:(LTResizeInterpolateCommandType)resizeType NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
