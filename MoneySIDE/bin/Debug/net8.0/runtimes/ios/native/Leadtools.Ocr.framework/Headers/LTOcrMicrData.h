// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrMicrData.h
//  Leadtools.Ocr
//

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrMicrData : NSObject <NSCopying>

@property (nonatomic, copy, nullable) NSString *auxiliary;
@property (nonatomic, copy, nullable) NSString *routing;
@property (nonatomic, copy, nullable) NSString *account;
@property (nonatomic, copy, nullable) NSString *checkNumber;
@property (nonatomic, copy, nullable) NSString *amount;

@property (nonatomic, assign)         wchar_t epc;

@end

NS_ASSUME_NONNULL_END
