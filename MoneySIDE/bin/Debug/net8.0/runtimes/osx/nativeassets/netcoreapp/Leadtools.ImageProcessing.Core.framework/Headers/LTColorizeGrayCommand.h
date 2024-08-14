// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTColorizeGrayCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTRasterColor.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorizeGrayCommandData : NSObject

@property (nonatomic, strong) LTRasterColor *color;
@property (nonatomic, assign) NSUInteger threshold;

- (instancetype)initWithColor:(LTRasterColor *)color threshold:(NSUInteger)threshold NS_DESIGNATED_INITIALIZER;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorizeGrayCommand : LTRasterCommand

@property (nonatomic, strong, readonly, nullable) LTRasterImage *destinationImage;
@property (nonatomic, strong)                     NSMutableArray<LTColorizeGrayCommandData *> *grayColors;

- (instancetype)initWithGrayColors:(NSArray<LTColorizeGrayCommandData *> *)grayColors NS_DESIGNATED_INITIALIZER;

@end


NS_ASSUME_NONNULL_END
