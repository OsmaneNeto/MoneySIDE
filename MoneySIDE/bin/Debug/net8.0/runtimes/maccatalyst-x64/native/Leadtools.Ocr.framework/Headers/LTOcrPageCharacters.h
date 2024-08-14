// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrPageCharacters.h
//  Leadtools.Ocr
//

#import <Leadtools.Ocr/LTOcrZoneCharacters.h>

@class LTOcrPage;

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrPageCharacters : NSObject <NSFastEnumeration>

@property (nonatomic, strong, readonly) LTOcrPage *page;

@property (nonatomic, assign, readonly) NSUInteger count;



- (void)addObject:(LTOcrZoneCharacters *)object NS_SWIFT_NAME(add(_:));
- (void)insertObject:(LTOcrZoneCharacters *)object atIndex:(NSUInteger)index NS_SWIFT_NAME(insert(_:at:));
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(LTOcrZoneCharacters *)object NS_SWIFT_NAME(replaceCharacter(at:with:));

- (void)removeLastObject;
- (void)removeAllObjects;
- (void)removeObjectAtIndex:(NSUInteger)index NS_SWIFT_NAME(remove(at:));

- (LTOcrZoneCharacters *)objectAtIndex:(NSUInteger)index NS_SWIFT_NAME(character(at:));

- (LTOcrZoneCharacters *)objectAtIndexedSubscript:(NSUInteger)index;
- (void)setObject:(LTOcrZoneCharacters *)object atIndexedSubscript:(NSUInteger)index;

- (void)enumerateObjectsUsingBlock:(void (^)(LTOcrZoneCharacters *characters, NSUInteger idx, BOOL *stop))block NS_SWIFT_NAME(enumerateCharacters(_:));

// bounds parameter is an array of LeadRect struct
- (BOOL)replaceIntersectedCharacters:(NSArray<NSValue *> *)bounds withCharacter:(char)replaceCharacter intersectionPercentage:(NSInteger)intersectionPercentage;
// bounds parameter is an array of LeadRect struct
- (BOOL)replaceIntersectedCharacters:(NSArray<NSValue *> *)bounds withCharacter:(char)replaceCharacter;

@end

NS_ASSUME_NONNULL_END
