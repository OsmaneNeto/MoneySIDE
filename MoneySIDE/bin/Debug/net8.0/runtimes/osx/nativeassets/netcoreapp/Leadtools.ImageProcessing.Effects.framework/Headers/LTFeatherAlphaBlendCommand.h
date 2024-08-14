// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTFeatherAlphaBlendCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTFeatherAlphaBlendCommand : LTRasterCommand

@property (nonatomic, strong, nullable) LTRasterImage *sourceImage;
@property (nonatomic, strong, nullable) LTRasterImage *maskImage;
@property (nonatomic, assign)           LeadRect destinationRectangle;
@property (nonatomic, assign)           LeadPoint sourcePoint;
@property (nonatomic, assign)           LeadPoint maskSourcePoint;

- (instancetype)initWithSourceImage:(LTRasterImage *)sourceImage sourcePoint:(LeadPoint)sourcePoint destinationRectangle:(LeadRect)destinationRectangle maskImage:(LTRasterImage *)maskImage maskSourcePoint:(LeadPoint)maskSourcePoint NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithSourceImage:(LTRasterImage *)sourceImage sourcePoint:(LeadPoint)sourcePoint destinationRectangle:(LeadRect)destinationRectangle maskImage:(LTRasterImage *)maskImage;

@end

NS_ASSUME_NONNULL_END
