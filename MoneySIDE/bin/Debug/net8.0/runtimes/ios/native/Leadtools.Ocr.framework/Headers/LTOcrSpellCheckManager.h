// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrSpellCheckManager.h
//  Leadtools.Ocr
//

#import <Leadtools.Ocr/LTOcrLanguage.h>

typedef NS_ENUM(NSInteger, LTOcrSpellCheckEngine) {
   LTOcrSpellCheckEngineNone = 0,
   LTOcrSpellCheckEngineNative
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrSpellCheckManager : NSObject

@property (nonatomic, copy, readonly)  NSArray<NSNumber *> *supportedSpellLanguages;
@property (nonatomic, copy, readonly)  NSArray<NSNumber *> *additionalSpellLanguages;

@property (nonatomic, copy, readonly)  NSArray<NSNumber *> *supportedSpellCheckEngines;


- (BOOL)isSpellLanguageSupported:(LTOcrLanguage)language;
- (LTOcrSpellCheckEngine)spellCheckEngine;
- (void)setSpellCheckEngine:(LTOcrSpellCheckEngine)spellCheckEngine error:(NSError **)error;
- (BOOL)isSpellCheckEngineSupported:(LTOcrSpellCheckEngine)spellCheckEngine;
- (void)addUserWords:(LTOcrLanguage)language words:(NSArray<NSString *> *)words error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
