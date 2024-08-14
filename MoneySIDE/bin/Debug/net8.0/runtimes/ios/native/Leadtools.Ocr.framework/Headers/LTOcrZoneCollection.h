// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrZoneCollection.h
//  Leadtools.Ocr
//

#import <Leadtools.Ocr/LTOcrZoneCell.h>
#import <Leadtools.Ocr/LTOcrZone.h>

@class LTOcrPage;

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrZoneCollection : NSObject <NSFastEnumeration>

@property (nonatomic, assign, readonly) NSUInteger count;

- (instancetype)init __unavailable;

- (void)addObject:(LTOcrZone *)object NS_SWIFT_NAME(add(_:));
- (void)insertObject:(LTOcrZone *)object atIndex:(NSUInteger)index NS_SWIFT_NAME(insert(_:at:));
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(LTOcrZone *)object NS_SWIFT_NAME(replaceZone(at:with:));

- (void)removeLastObject;
- (void)removeAllObjects;
- (void)removeObjectAtIndex:(NSUInteger)index NS_SWIFT_NAME(remove(at:));

- (LTOcrZone *)objectAtIndex:(NSUInteger)index NS_SWIFT_NAME(zone(at:));

- (LTOcrZone *)objectAtIndexedSubscript:(NSUInteger)index;
- (void)setObject:(LTOcrZone *)object atIndexedSubscript:(NSUInteger)index;

- (void)enumerateObjectsUsingBlock:(void (^)(LTOcrZone *zone, NSUInteger idx, BOOL *stop))block NS_SWIFT_NAME(enumerateZones(_:));

- (nullable NSArray<LTOcrZoneCell *> *)zoneCellsAtIndex:(NSUInteger)index error:(NSError **)error NS_SWIFT_NAME(zoneCells(at:));
- (BOOL)setZoneCells:(nullable NSArray<LTOcrZoneCell *> *)zoneCells atIndex:(NSUInteger)index error:(NSError **)error NS_SWIFT_NAME(setZoneCells(_:at:));

@end

NS_ASSUME_NONNULL_END
