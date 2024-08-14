// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTEffectsUtilities.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTPrimitives.h>

typedef NS_ENUM(NSInteger, LTCurvePointsType) {
    LTCurvePointsTypeCurve  = 0x0000,
    LTCurvePointsTypeLinear = 0x0001
};

typedef NS_OPTIONS(NSUInteger, LTFunctionalLookupTableFlags) {
    LTFunctionalLookupTableFlagsExponential = 0x0000,
    LTFunctionalLookupTableFlagsLogarithm   = 0x0001,
    LTFunctionalLookupTableFlagsLinear      = 0x0002,
    LTFunctionalLookupTableFlagsSigmoid     = 0x0003,
    LTFunctionalLookupTableFlagsSigned      = 0x0010
};

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTEffectsUtilities : NSObject

+ (NSUInteger)getCurvePoints:(int *)curve userPoints:(const LeadPoint *)userPoints userPointsCount:(NSUInteger)userPointsCount type:(LTCurvePointsType)type error:(NSError **)error;
+ (void)getFunctionalLookupTable:(int *)lookupTable lookupTableLength:(NSUInteger)lookupTableLength start:(NSInteger)start end:(NSInteger)end factor:(NSInteger)factor flags:(LTFunctionalLookupTableFlags)flags error:(NSError **)error;
+ (NSUInteger)getUserLookupTable:(unsigned int *)lookupTable lookupTableLength:(NSUInteger)lookupTableLength userPoints:(const LeadPoint *)userPoints userPointsCount:(NSUInteger)userPointsCount error:(NSError **)error;

@end
