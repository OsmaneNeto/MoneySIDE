// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTGrayscaleToDuotoneCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

#import <Leadtools.ImageProcessing.Color/LTEnums.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTGrayscaleToDuotoneCommand : LTRasterCommand

@property (nonatomic, strong, getter=getNewColor) NSMutableArray<LTRasterColor *> *newColor;
@property (nonatomic, copy)                       LTRasterColor *color;

@property (nonatomic, assign) LTGrayScaleToDuotoneCommandMixingType type;

- (instancetype)initWithNewColor:(NSArray<LTRasterColor *> *)newColor color:(LTRasterColor *)color type:(LTGrayScaleToDuotoneCommandMixingType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
