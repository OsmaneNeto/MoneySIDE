// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTEdgeDetectorCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTEdgeDetectorCommandType) {
    LTEdgeDetectorCommandTypeSobelVertical      = 0x0101,
    LTEdgeDetectorCommandTypeSobelHorizontal    = 0x0102,
    LTEdgeDetectorCommandTypeSobelBoth          = 0x0103,
    
    LTEdgeDetectorCommandTypePrewittVertical    = 0x0201,
    LTEdgeDetectorCommandTypePrewittHorizontal  = 0x0202,
    LTEdgeDetectorCommandTypePrewittBoth        = 0x0203,
    
    LTEdgeDetectorCommandTypeLaplace1           = 0x0301,
    LTEdgeDetectorCommandTypeLaplace2           = 0x0302,
    LTEdgeDetectorCommandTypeLaplace3           = 0x0303,
    LTEdgeDetectorCommandTypeLaplaceDiagonal    = 0x0304,
    LTEdgeDetectorCommandTypeLaplaceHorizontal  = 0x0305,
    LTEdgeDetectorCommandTypeLaplaceVertical    = 0x0306,
    
    LTEdgeDetectorCommandTypeGradientNorth      = 0x0401,
    LTEdgeDetectorCommandTypeGradientNorthEast  = 0x0402,
    LTEdgeDetectorCommandTypeGradientEast       = 0x0403,
    LTEdgeDetectorCommandTypeGradientSouthEast  = 0x0404,
    LTEdgeDetectorCommandTypeGradientSouth      = 0x0405,
    LTEdgeDetectorCommandTypeGradientSouthWest  = 0x0406,
    LTEdgeDetectorCommandTypeGradientWest       = 0x0407,
    LTEdgeDetectorCommandTypeGradientNorthWest  = 0x0408
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTEdgeDetectorCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger threshold;
@property (nonatomic, assign) LTEdgeDetectorCommandType filter;

- (instancetype)initWithThreshold:(NSInteger)threshold filter:(LTEdgeDetectorCommandType)filter NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
