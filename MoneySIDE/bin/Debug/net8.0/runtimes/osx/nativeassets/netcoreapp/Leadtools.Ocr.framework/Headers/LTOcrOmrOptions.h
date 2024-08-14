// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrOmrOptions.h
//  Leadtools.Ocr
//

typedef NS_ENUM(NSInteger, LTOcrOmrSensitivity) {
   LTOcrOmrSensitivityHighest = 0,
   LTOcrOmrSensitivityHigh,
   LTOcrOmrSensitivityLow,
   LTOcrOmrSensitivityLowest,
   LTOcrOmrSensitivityLast = LTOcrOmrSensitivityLowest
};

typedef NS_ENUM(NSInteger, LTOcrOmrFrameDetectionMethod) {
   LTOcrOmrFrameDetectionMethodAuto = 0,
   LTOcrOmrFrameDetectionMethodWithoutFrame,
   LTOcrOmrFrameDetectionMethodWithFrame,
   LTOcrOmrFrameDetectionMethodLast = LTOcrOmrFrameDetectionMethodWithFrame
};

typedef NS_ENUM(NSInteger, LTOcrOmrZoneState) {
   LTOcrOmrZoneStateUnfilled = 0,
   LTOcrOmrZoneStateFilled
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrOmrOptions : NSObject

@property (nonatomic, assign) LTOcrOmrFrameDetectionMethod frameDetectionMethod;
@property (nonatomic, assign) LTOcrOmrSensitivity sensitivity;

- (unichar)recognitionCharacterForState:(LTOcrOmrZoneState)state;
- (void)setRecognitionCharacter:(unichar)character forState:(LTOcrOmrZoneState)state;

@end

NS_ASSUME_NONNULL_END
