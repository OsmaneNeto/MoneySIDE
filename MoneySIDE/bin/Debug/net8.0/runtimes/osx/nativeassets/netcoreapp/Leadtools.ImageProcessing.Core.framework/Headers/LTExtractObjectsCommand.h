// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTExtractObjectsCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTPrimitives.h>
#import <Leadtools/LTRasterCommand.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

typedef NS_ENUM(NSUInteger, LTExObjDirection) {
    LTExObjDirectionEast = 0,
    LTExObjDirectionNorth = 1,
    LTExObjDirectionWest = 2,
    LTExObjDirectionSouth = 3
};

typedef NS_ENUM(NSUInteger, LTExObjLocation) {
    LTExObjLocationAfter = 0,
    LTExObjLocationBefore = 1,
    LTExObjLocationChild = 2,
    LTExObjLocationSibling = 3
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@class LTExObjFilterOptions;
@class LTExObjObject;
@class LTExObjObjectList;
@class LTExObjOutlinePointList;
@class LTExObjRegionOptions;
@class LTExObjResult;
@class LTExObjSegmentList;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjColorInfo : NSObject

@property (nonatomic, strong) LTRasterColor * color;
@property (nonatomic, assign) NSUInteger threshold;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjContentBound : NSObject

- (instancetype)init __unavailable;
- (instancetype)initWithInput:(LeadRect)input;

@property (nonatomic, readonly) LeadRect content;
@property (nonatomic, assign) LeadRect input;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjContentBoundOptions : NSObject

@property (nonatomic, assign) NSUInteger fullObjectMargin;
@property (nonatomic, strong, nullable) NSEnumerator<LTExObjObject *> * objectsOfInterest;
@property (nonatomic, assign) BOOL optimizedForRepetition;

- (void)clearInternalCache;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjData : NSObject <NSFastEnumeration>

- (instancetype)init __unavailable;

@property (nonatomic, readonly) NSUInteger count;

- (void)calculateContentBound:(NSEnumerator<LTExObjContentBound *> *)bounds withOptions:(LTExObjContentBoundOptions *)options;
- (void)calculateRegion:(NSEnumerator<LTExObjObject *> *)objects withOptions:(LTExObjRegionOptions *)options;
- (void)filterList:(LTExObjObjectList *)objects withOptions:(LTExObjFilterOptions *)options;
- (LTExObjResult *)objectAtIndexedSubscript:(NSUInteger)index;
- (NSEnumerator<LTExObjResult *> *)objectEnumerator;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjFilterOptions : NSObject

@property (nonatomic, assign) BOOL invertRange;
@property (nonatomic, assign) NSInteger largeObjectThreshold;
@property (nonatomic, assign) BOOL reportRemovedObjects;
@property (nonatomic, strong, readonly, nullable) LTExObjObjectList * removed;
@property (nonatomic, assign) NSInteger smallObjectThreshold;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjObject : NSObject

@property (nonatomic, strong, readonly, nullable) LTExObjObjectList * children;
@property (nonatomic, strong, readonly, nullable) LTExObjOutlinePointList * outline;
@property (nonatomic, strong, readonly, nullable) LTExObjSegmentList * regionHorizontal;
@property (nonatomic, strong, readonly, nullable) LTExObjSegmentList * regionVertical;
@property (nonatomic, strong, readonly, nullable) LTExObjObjectList * siblings;
@property (nonatomic, assign) LeadRect totalBounds;
@property (nonatomic, assign) BOOL whiteOnBlack;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjObjectList : NSObject <NSFastEnumeration>

- (instancetype)init __unavailable;

@property (nonatomic, readonly) NSUInteger count;

- (void)add:(LTExObjObject *)item;
- (void)add:(LTExObjObject *)item withNeighbor:(LTExObjObject * __nullable)neighbor atLocation:(LTExObjLocation)location;
- (void)clear;
- (BOOL)contains:(LTExObjObject *)item;
- (void)move:(LTExObjObject *)item to:(LTExObjObjectList * __nullable)target withNeighbor:(LTExObjObject * __nullable)neighbor atLocation:(LTExObjLocation)location;
- (NSEnumerator<LTExObjObject *> *)objectEnumerator;
- (BOOL)remove:(LTExObjObject *)item;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjOutlinePoint : NSObject

- (instancetype)init __unavailable;

@property (nonatomic, readonly) LTExObjDirection direction;
@property (nonatomic, readonly) LeadPoint position;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjOutlinePointList : NSObject <NSFastEnumeration>

- (instancetype)init __unavailable;

@property (nonatomic, readonly) LeadRect bounds;
@property (nonatomic, readonly) NSUInteger count;

- (NSEnumerator<LTExObjOutlinePoint *> *)objectEnumerator;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjRegionOptions : NSObject

@property (nonatomic, assign) BOOL horizontal;
@property (nonatomic, assign) BOOL vertical;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjResult : NSObject

- (instancetype)init __unavailable;

@property (nonatomic, strong, readonly, nullable) LTExObjObjectList * containers;
@property (nonatomic, strong, readonly, nullable) LTExObjObjectList * largeNoise;
@property (nonatomic, strong, readonly, nullable) LTExObjObjectList * objects;
@property (nonatomic, strong, readonly, nullable) LTExObjObjectList * smallNoise;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjSegment : NSObject

- (instancetype)init __unavailable;

@property (nonatomic, readonly) LeadRect bounds;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExObjSegmentList : NSObject <NSFastEnumeration>

- (instancetype)init __unavailable;

@property (nonatomic, readonly) NSUInteger count;
@property (nonatomic, readonly) NSUInteger totalArea;

- (NSEnumerator<LTExObjSegment *> *)objectEnumerator;

@end

NS_ASSUME_NONNULL_END

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTExtractObjectsCommand : LTRasterCommand

@property (nonatomic, assign) BOOL checkContainerSubchildren;
@property (nonatomic, assign) BOOL checkForTables;
@property (nonatomic, strong, nullable) NSArray<LTExObjColorInfo *> * colorInfo;
@property (nonatomic, assign) NSUInteger containerMinCount;
@property (nonatomic, strong, readonly, nullable) LTExObjData * data;
@property (nonatomic, assign) BOOL eightConnectivity;
@property (nonatomic, assign) BOOL ignoreContainers;
@property (nonatomic, assign) BOOL ignoreLargeNoise;
@property (nonatomic, assign) BOOL ignoreSmallNoise;
@property (nonatomic, assign) NSInteger largeNoiseThreshold;
@property (nonatomic, assign) BOOL nested;
@property (nonatomic, assign) BOOL outline;
@property (nonatomic, assign) BOOL reportIgnored;
@property (nonatomic, assign) LeadRect roi;
@property (nonatomic, assign) NSInteger smallNoiseThreshold;
@property (nonatomic, assign) double tableMaxBorderPercent;
@property (nonatomic, assign) NSInteger tableSizeThreshold;
@property (nonatomic, assign) BOOL useMultiColors;
@property (nonatomic, assign) BOOL useROI;

@end

NS_ASSUME_NONNULL_END
