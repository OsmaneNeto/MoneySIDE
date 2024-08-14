// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOmrCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

typedef NS_ENUM(NSInteger, LTOmrZoneState) {
    LTOmrZoneStateUnfilled = 0,
    LTOmrZoneStateFilled = 1,
};

typedef NS_ENUM(NSInteger, LTOmrFrameDetectionMethod) {
    LTOmrFrameDetectionMethodAuto,
    LTOmrFrameDetectionMethodWithoutFrame,
    LTOmrFrameDetectionMethodWithFrame
};

typedef NS_ENUM(NSInteger, LTOmrSensitivity) {
    LTOmrSensitivityHighest,
    LTOmrSensitivityHigh,
    LTOmrSensitivityLow,
    LTOmrSensitivityLowest
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOmrZone : NSObject

@property (nonatomic, assign) NSInteger confidence;
@property (nonatomic, assign) LeadRect bounds;
@property (nonatomic, assign) LTOmrZoneState state;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOmrCommand : LTRasterCommand

@property (nonatomic, strong, readonly) NSMutableArray<LTOmrZone *> *zones;
@property (nonatomic, assign)           LTOmrFrameDetectionMethod frameDetectionMethod;
@property (nonatomic, assign)           LTOmrSensitivity sensitivity;

- (instancetype)initWithFrameDetectionMethod:(LTOmrFrameDetectionMethod)frameDetectionMethod sensitivity:(LTOmrSensitivity)sensitivity NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
