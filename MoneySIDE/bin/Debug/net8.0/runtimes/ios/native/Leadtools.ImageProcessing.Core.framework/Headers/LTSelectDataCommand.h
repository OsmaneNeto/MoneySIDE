// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSelectDataCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSelectDataCommand : LTRasterCommand

@property (nonatomic, assign, readonly, nullable)   LTRasterImage* destinationImage;
@property (nonatomic, retain)                       LTRasterColor* color;
@property (nonatomic, assign)                       NSUInteger sourceLowBit;
@property (nonatomic, assign)                       NSUInteger sourceHighBit;
@property (nonatomic, assign)                       NSUInteger threshold;
@property (nonatomic, assign)                       BOOL combine;

- (instancetype)initWithColor:(LTRasterColor*)color sourceLowBit:(NSUInteger)sourceLowBit sourceHighBit:(NSUInteger)sourceHighBit threshold:(NSUInteger)threshold combine:(BOOL)combine NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
