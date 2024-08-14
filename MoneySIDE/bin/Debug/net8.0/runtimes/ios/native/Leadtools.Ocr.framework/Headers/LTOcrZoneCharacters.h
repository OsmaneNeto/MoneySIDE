// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrZoneCharacters.h
//  Leadtools.Ocr
//

#import <Leadtools.Ocr/LTOcrMicrData.h>
#import <Leadtools.Ocr/LTOcrCharacter.h>
#import <Leadtools.Ocr/LTOcrWord.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrZoneCharacters : NSObject <NSFastEnumeration, NSCopying>

@property (nonatomic, assign, readonly)         NSUInteger count;
@property (nonatomic, assign, readonly)         NSUInteger zoneIndex;
@property (nonatomic, copy, readonly, nullable) NSArray<LTOcrWord *> *words;


- (nullable LTOcrMicrData *)extractMicrData;

- (void)addObject:(LTOcrCharacter *)object NS_SWIFT_NAME(add(_:));
- (void)insertObject:(LTOcrCharacter *)object atIndex:(NSUInteger)index NS_SWIFT_NAME(insert(_:at:));
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(LTOcrCharacter *)object NS_SWIFT_NAME(replaceCharacter(at:with:));

- (void)removeLastObject;
- (void)removeAllObjects;
- (void)removeObjectAtIndex:(NSUInteger)index NS_SWIFT_NAME(remove(at:));

- (LTOcrCharacter *)objectAtIndex:(NSUInteger)index NS_SWIFT_NAME(character(at:));

- (LTOcrCharacter *)objectAtIndexedSubscript:(NSUInteger)index;
- (void)setObject:(LTOcrCharacter *)object atIndexedSubscript:(NSUInteger)index;

- (void)enumerateObjectsUsingBlock:(void (^)(LTOcrCharacter *character, NSUInteger idx, BOOL *stop))block NS_SWIFT_NAME(enumerateCharacters(_:));

@end

NS_ASSUME_NONNULL_END
