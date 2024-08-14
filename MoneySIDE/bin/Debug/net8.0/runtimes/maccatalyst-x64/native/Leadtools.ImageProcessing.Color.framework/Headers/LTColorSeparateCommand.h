// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTColorSeparateCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>

typedef NS_ENUM(NSInteger, LTColorSeparateCommandType) {
    LTColorSeparateCommandTypeRgb   = 0x0000,
    LTColorSeparateCommandTypeCmyk  = 0x0001,
    LTColorSeparateCommandTypeHsv   = 0x0002,
    LTColorSeparateCommandTypeHls   = 0x0003,
    LTColorSeparateCommandTypeCmy   = 0x0004,
    LTColorSeparateCommandTypeYuv   = 0x0005,
    LTColorSeparateCommandTypeXyz   = 0x0006,
    LTColorSeparateCommandTypeLab   = 0x0007,
    LTColorSeparateCommandTypeYcrcb = 0x0008,
    LTColorSeparateCommandTypeSct   = 0x0009,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorSeparateCommand : LTRasterCommand

@property (nonatomic, assign)                     LTColorSeparateCommandType type;
@property (nonatomic, strong, readonly, nullable) LTRasterImage *destinationImage;

- (instancetype)initWithType:(LTColorSeparateCommandType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
