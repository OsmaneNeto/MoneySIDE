// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSpatialFilterCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTSpatialFilterCommandPredefined) {
    LTSpatialFilterCommandPredefinedEmbossNorth,
    LTSpatialFilterCommandPredefinedEmbossNorthEast,
    LTSpatialFilterCommandPredefinedEmbossEast,
    LTSpatialFilterCommandPredefinedEmbossSouthEast,
    LTSpatialFilterCommandPredefinedEmbossSouth,
    LTSpatialFilterCommandPredefinedEmbossSouthWest,
    LTSpatialFilterCommandPredefinedEmbossWest,
    LTSpatialFilterCommandPredefinedEmbossNorthWest,
    LTSpatialFilterCommandPredefinedGradientEdgeEnhancementNorth,
    LTSpatialFilterCommandPredefinedGradientEdgeEnhancementNorthEast,
    LTSpatialFilterCommandPredefinedGradientEdgeEnhancementEast,
    LTSpatialFilterCommandPredefinedGradientEdgeEnhancementSouthEast,
    LTSpatialFilterCommandPredefinedGradientEdgeEnhancementSouth,
    LTSpatialFilterCommandPredefinedGradientEdgeEnhancementSouthWest,
    LTSpatialFilterCommandPredefinedGradientEdgeEnhancementWest,
    LTSpatialFilterCommandPredefinedGradientEdgeEnhancementNorthWest,
    LTSpatialFilterCommandPredefinedLaplacianFilter1,
    LTSpatialFilterCommandPredefinedLaplacianFilter2,
    LTSpatialFilterCommandPredefinedLaplacianFilter3,
    LTSpatialFilterCommandPredefinedLaplacianDiagonal,
    LTSpatialFilterCommandPredefinedLaplacianHorizontal,
    LTSpatialFilterCommandPredefinedLaplacianVertical,
    LTSpatialFilterCommandPredefinedSobelHorizontal,
    LTSpatialFilterCommandPredefinedSobelVertical,
    LTSpatialFilterCommandPredefinedPrewittHorizontal,
    LTSpatialFilterCommandPredefinedPrewittVertical,
    LTSpatialFilterCommandPredefinedShiftAndDifferenceDiagonal,
    LTSpatialFilterCommandPredefinedShiftAndDifferenceHorizontal,
    LTSpatialFilterCommandPredefinedShiftAndDifferenceVertical,
    LTSpatialFilterCommandPredefinedLineSegmentHorizontal,
    LTSpatialFilterCommandPredefinedLineSegmentVertical,
    LTSpatialFilterCommandPredefinedLineSegmentLeftToRight,
    LTSpatialFilterCommandPredefinedLineSegmentRightToLeft,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSpatialFilterCommand : LTRasterCommand

@property (nonatomic, assign)           NSInteger divisor;
@property (nonatomic, assign)           NSInteger bias;
@property (nonatomic, assign, readonly) NSInteger dimension;

@property (nonatomic, copy, nullable)   NSArray<NSNumber *> *matrix;

- (instancetype)initWithPredefinedSpatialFilter:(LTSpatialFilterCommandPredefined)predefined NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithDivisor:(NSInteger)divisor bias:(NSInteger)bias matrix:(nullable NSArray<NSNumber *> *)matrix NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
