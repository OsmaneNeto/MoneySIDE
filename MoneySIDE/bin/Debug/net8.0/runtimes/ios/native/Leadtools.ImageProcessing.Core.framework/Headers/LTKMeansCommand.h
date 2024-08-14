// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTKMeansCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

typedef NS_OPTIONS(NSUInteger, LTKMeansCommandFlags) {
    LTKMeansCommandFlagsRandom      = 0x0001,
    LTKMeansCommandFlagsUniform     = 0x0002,
    LTKMeansCommandFlagsUserDefined = 0x0003
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTKMeansCommand : LTRasterCommand

@property (nonatomic, assign)                     NSInteger clusters;
@property (nonatomic, assign)                     LTKMeansCommandFlags type;
@property (nonatomic, strong, nullable)           NSArray<LTRasterColor *> *inCenters;
@property (nonatomic, strong, readonly, nullable) NSArray<LTRasterColor *> *outCenters;

- (instancetype)initWithClusters:(NSInteger)clusters type:(LTKMeansCommandFlags)type inCenters:(nullable NSArray<LTRasterColor *> *)inCenters NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
