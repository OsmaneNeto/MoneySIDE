// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAlphaBlendCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAlphaBlendCommand : LTRasterCommand

@property (nonatomic, strong, nullable) LTRasterImage *sourceImage;
@property (nonatomic, assign)           LeadRect destinationRectangle;
@property (nonatomic, assign)           LeadPoint sourcePoint;
@property (nonatomic, assign)           NSInteger opacity;

- (instancetype)initWithSourceImage:(LTRasterImage *)sourceImage sourcePoint:(LeadPoint)sourcePoint destinationRect:(LeadRect)destinationRect opacity:(NSInteger)opacity NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
