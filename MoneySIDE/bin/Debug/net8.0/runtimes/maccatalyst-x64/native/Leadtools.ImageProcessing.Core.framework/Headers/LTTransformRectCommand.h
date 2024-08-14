// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTTransformRectCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

typedef NS_ENUM(NSInteger, LTTransformationType) {
    LTTransformationXYS     = 0x0,
    LTTransformationXYRS    = 0x1
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTTransformRectCommand : LTRasterCommand

@property (nonatomic, assign) BOOL findXScaleFromYScale;
@property (nonatomic, assign) BOOL trustedXScale;
@property (nonatomic, assign) LTTransformationType transformation;
@property (nonatomic, assign) BOOL minimizeVerticalProjection;
@property (nonatomic, assign) NSNumber* vMatchingError;
@property (nonatomic, assign) NSNumber* shearingFactor;
@property (nonatomic, assign) NSNumber* rotationAngle;
@property (nonatomic, assign) NSNumber* matchingError;
@property (nonatomic, assign) LeadRect mappedRect;
@property (nonatomic, strong) NSMutableArray<NSNumber *> *transformationMatrix;
@property (nonatomic, strong) NSMutableArray<NSValue *> *alignmentError;
@property (nonatomic, strong) NSMutableArray<NSValue *> *masterImagePoints;
@property (nonatomic, strong) NSMutableArray<NSValue *> *filledImagePoints;

-(LeadPoint)transformPoint:(LeadPoint)point transMatrix:(NSMutableArray *)transMatrix;

@end

NS_ASSUME_NONNULL_END
