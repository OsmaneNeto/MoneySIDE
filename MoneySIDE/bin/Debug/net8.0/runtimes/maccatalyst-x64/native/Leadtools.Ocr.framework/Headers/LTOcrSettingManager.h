// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrSettingManager.h
//  Leadtools.Ocr
//

#import <Leadtools/LTLeadtools.h>
#import <Leadtools.Ocr/LTOcrSettingDescriptor.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrSettingManager : NSObject

@property (nonatomic, strong, readonly) NSArray<NSString *> *settingNames;

- (BOOL)isSettingNameSupported:(NSString *)settingName;

- (LTOcrSettingValueType)valueTypeForSetting:(NSString *)settingName;
- (LTOcrSettingDescriptor *)descriptorForSetting:(NSString *)settingName;

- (NSInteger)integerValueForSetting:(NSString *)settingName;
- (void)setIntegerValue:(NSInteger)value forSetting:(NSString *)settingName;

- (NSInteger)enumValueForSetting:(NSString *)settingName;
- (void)setEnumValue:(NSInteger)value forSetting:(NSString *)settingName;
- (nullable NSString *)enumStringValueForSetting:(NSString *)settingName;
- (void)setEnumStringValue:(NSString *)value forSetting:(NSString *)settingName;

- (double)doubleValueForSetting:(NSString *)settingName;
- (void)setDoubleValue:(double)value forSetting:(NSString *)settingName;

- (BOOL)booleanValueForSetting:(NSString *)settingName;
- (void)setBooleanValue:(BOOL)value forSetting:(NSString *)settingName;

- (nullable NSString *)stringValueForSetting:(NSString *)settingName;
- (void)setStringValue:(NSString *)value forSetting:(NSString *)settingName;

- (nullable NSString *)valueForSetting:(NSString *)settingName;
- (void)setValue:(NSString *)value forSetting:(NSString *)settingName;

@end



@interface LTOcrSettingManager (Deprecated)

- (nullable NSArray *)getSettingNames LT_DEPRECATED_USENEW(19_0, "settingNames");
- (LTOcrSettingValueType)getSettingValueType:(NSString *)settingName LT_DEPRECATED_USENEW(19_0, "valueTypeForSetting:");
- (LTOcrSettingDescriptor *)getSettingDescriptor:(NSString *)settingName LT_DEPRECATED_USENEW(19_0, "descriptorForSetting:");

- (int)getEnumValue:(NSString *)settingName LT_DEPRECATED_USENEW(19_0, "enumValueForSetting:");
- (void)setEnumValue:(NSString *)settingName value:(int)value LT_DEPRECATED_USENEW(19_0, "setEnumValue:forSetting:");
- (nullable NSString *)getEnumValueAsString:(NSString *)settingName LT_DEPRECATED_USENEW(19_0, "enumStringValueForSetting:");
- (void)setEnumValueAsString:(NSString *)settingName value:(NSString *)value LT_DEPRECATED_USENEW(19_0, "setEnumStringValue:forSetting:");

- (double)getDoubleValue:(NSString *)settingName LT_DEPRECATED_USENEW(19_0, "doubleValueForSetting:");
- (void)setDoubleValue:(NSString *)settingName value:(double)value LT_DEPRECATED_USENEW(19_0, "setDoubleValue:forSetting:");

- (BOOL)getBooleanValue:(NSString *)settingName LT_DEPRECATED_USENEW(19_0, "booleanValueForSetting:");
- (void)setBooleanValue:(NSString *)settingName value:(BOOL)value LT_DEPRECATED_USENEW(19_0, "setBooleanValue:forSetting:");

- (nullable NSString *)getStringValue:(NSString *)settingName LT_DEPRECATED_USENEW(19_0, "stringValueForSetting:");
- (void)setStringValue:(NSString *)settingName value:(NSString *)value LT_DEPRECATED_USENEW(19_0, "setStringValue:forSetting:");

- (void)setValue:(NSString *)settingName value:(NSString *)value LT_DEPRECATED_USENEW(19_0, "valueForSetting:");
- (nullable NSString *)getValue:(NSString *)settingName LT_DEPRECATED_USENEW(19_0, "setValue:forSetting:");

@end

NS_ASSUME_NONNULL_END
