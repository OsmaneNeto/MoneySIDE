// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrZoneManager.h
//  Leadtools.Ocr
//

#import <Leadtools.Ocr/LTOcrOmrOptions.h>
#import <Leadtools.Ocr/LTOcrZoneType.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrZoneManager : NSObject

@property (nonatomic, strong, readonly) LTOcrOmrOptions *omrOptions;

@property (nonatomic, copy, readonly)  NSArray<NSNumber *> *supportedZoneTypes;

- (BOOL)isZoneTypeSupported:(LTOcrZoneType)zoneType;

@end

NS_ASSUME_NONNULL_END
