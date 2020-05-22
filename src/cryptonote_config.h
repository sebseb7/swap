// Copyright (c) 2014-2019, The Monero Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <stdexcept>
#include <string>
#include <boost/uuid/uuid.hpp>

#define CRYPTONOTE_DNS_TIMEOUT_MS                       20000

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_GETBLOCKTEMPLATE_MAX_BLOCK_SIZE	196608 //size of block (bytes) that is the maximum that miners will produce
#define CRYPTONOTE_MAX_TX_SIZE                          1000000
#define CRYPTONOTE_MAX_TX_PER_BLOCK                     0x10000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER          0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            60
#define CURRENT_TRANSACTION_VERSION                     2
#define CURRENT_BLOCK_MAJOR_VERSION                     9
#define CURRENT_BLOCK_MINOR_VERSION                     9
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              60*60*2
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE             10

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               60

// MONEY_SUPPLY - total number coins to be generated
#define MONEY_SUPPLY                                    ((uint64_t)(480000000000000000))
#define EMISSION_SPEED_FACTOR_PER_MINUTE                (20)
#define FINAL_SUBSIDY_PER_MINUTE                        ((uint64_t)5000000000) // 3 * pow(10, 11)

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    60000 //size of block (bytes) after which reward for block calculated using block size
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    20000 //size of block (bytes) after which reward for block calculated using block size - before first fork
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5    300000 //size of block (bytes) after which reward for block calculated using block size - second change, from v5
#define CRYPTONOTE_LONG_TERM_BLOCK_WEIGHT_WINDOW_SIZE   100000 // size in blocks of the long term block weight median window
#define CRYPTONOTE_SHORT_TERM_BLOCK_WEIGHT_SURGE_FACTOR 50
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                9
// COIN - number of smallest units in one coin
#define COIN                                            ((uint64_t)1000000000000) // pow(10, 12)

#define FEE_PER_KB_OLD                                  ((uint64_t)10000000000) // pow(10, 10)
#define FEE_PER_KB                                      ((uint64_t)2000000000) // 2 * pow(10, 9)
#define FEE_PER_BYTE                                    ((uint64_t)300000)
#define DYNAMIC_FEE_PER_KB_BASE_FEE                     ((uint64_t)2000000000) // 2 * pow(10,9)
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD            ((uint64_t)10000000000000) // 10 * pow(10,12)
#define DYNAMIC_FEE_PER_KB_BASE_FEE_V5                  ((uint64_t)2000000000 * (uint64_t)CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 / CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5)
#define DYNAMIC_FEE_REFERENCE_TRANSACTION_WEIGHT         ((uint64_t)3000)

#define ORPHANED_BLOCKS_MAX_COUNT                       100


#define DIFFICULTY_TARGET_V2                            15  // seconds
#define DIFFICULTY_TARGET_V1                            15  // seconds - before first fork
#define DIFFICULTY_WINDOW                               720 // blocks
#define DIFFICULTY_LAG                                  15  // !!!
#define DIFFICULTY_CUT                                  60  // timestamps to cut after sorting
#define DIFFICULTY_BLOCKS_COUNT                         DIFFICULTY_WINDOW + DIFFICULTY_LAG


#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V1   DIFFICULTY_TARGET_V1 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V2   DIFFICULTY_TARGET_V2 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1


#define DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN             DIFFICULTY_TARGET_V1 //just alias; used by tests


#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000  //by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT_PRE_V4       100    //by default, blocks count in blocks downloading
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              20     //by default, blocks count in blocks downloading
#define BLOCKS_SYNCHRONIZING_MAX_COUNT                  2048   //must be a power of 2, greater than 128, equal to SEEDHASH_EPOCH_BLOCKS

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                    (86400*3) //seconds, three days
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME     604800 //seconds, one week


#define CRYPTONOTE_DANDELIONPP_STEMS              2 // number of outgoing stem connections per epoch
#define CRYPTONOTE_DANDELIONPP_FLUFF_PROBABILITY 10 // out of 100
#define CRYPTONOTE_DANDELIONPP_MIN_EPOCH         10 // minutes
#define CRYPTONOTE_DANDELIONPP_EPOCH_RANGE       30 // seconds
#define CRYPTONOTE_DANDELIONPP_FLUSH_AVERAGE      5 // seconds average for poisson distributed fluff flush
#define CRYPTONOTE_DANDELIONPP_EMBARGO_AVERAGE  173 // seconds (see tx_pool.cpp for more info)

// see src/cryptonote_protocol/levin_notify.cpp
#define CRYPTONOTE_NOISE_MIN_EPOCH                      5      // minutes
#define CRYPTONOTE_NOISE_EPOCH_RANGE                    30     // seconds
#define CRYPTONOTE_NOISE_MIN_DELAY                      10     // seconds
#define CRYPTONOTE_NOISE_DELAY_RANGE                    5      // seconds
#define CRYPTONOTE_NOISE_BYTES                          3*1024 // 3 KiB
#define CRYPTONOTE_NOISE_CHANNELS                       2      // Max outgoing connections per zone used for noise/covert sending

#define CRYPTONOTE_MAX_FRAGMENTS                        20 // ~20 * NOISE_BYTES max payload size for covert/noise send

#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           1000

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_DEFAULT_CONNECTIONS_COUNT                   8
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60           //secondes
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000     //50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000       //5 seconds
#define P2P_DEFAULT_SOCKS_CONNECT_TIMEOUT               45         // seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000       //2 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60*2*1000  //2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000       //5 seconds
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_ANCHOR_CONNECTIONS_COUNT            2
#define P2P_DEFAULT_SYNC_SEARCH_CONNECTIONS_COUNT       2
#define P2P_DEFAULT_LIMIT_RATE_UP                       2048       // kB/s
#define P2P_DEFAULT_LIMIT_RATE_DOWN                     8192       // kB/s

#define P2P_FAILED_ADDR_FORGET_SECONDS                  (60*60)     //1 hour
#define P2P_IP_BLOCKTIME                                (60*60*24)  //24 hour
#define P2P_IP_FAILS_BEFORE_BLOCK                       10
#define P2P_IDLE_CONNECTION_KILL_INTERVAL               (5*60) //5 minutes

#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS                  0x01
#define P2P_SUPPORT_FLAGS                               P2P_SUPPORT_FLAG_FLUFFY_BLOCKS

#define RPC_IP_FAILS_BEFORE_BLOCK                       3

#define CRYPTONOTE_NAME                         "bittubecash"
#define CRYPTONOTE_POOLDATA_FILENAME            "poolstate.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME      "data.mdb"
#define CRYPTONOTE_BLOCKCHAINDATA_LOCK_FILENAME "lock.mdb"
#define P2P_NET_DATA_FILENAME                   "p2pstate.bin"
#define RPC_PAYMENTS_DATA_FILENAME              "rpcpayments.bin"
#define MINER_CONFIG_FILE_NAME                  "miner_conf.json"

#define THREAD_STACK_SIZE                       5 * 1024 * 1024

#define HF_VERSION_DYNAMIC_FEE                  4
#define HF_VERSION_DEV_REWARD                   12
#define HF_VERSION_MIN_MIXIN_4                  6
#define HF_VERSION_MIN_MIXIN_6                  7
#define HF_VERSION_MIN_MIXIN_10                 8
#define HF_VERSION_ENFORCE_RCT                  6
#define HF_VERSION_PER_BYTE_FEE                 8
#define HF_VERSION_SMALLER_BP                   10
#define HF_VERSION_LONG_TERM_BLOCK_WEIGHT       10
#define HF_VERSION_MIN_2_OUTPUTS                12
#define HF_VERSION_MIN_V2_COINBASE_TX           12
#define HF_VERSION_SAME_MIXIN                   12
#define HF_VERSION_REJECT_SIGS_IN_COINBASE      12
#define HF_VERSION_ENFORCE_MIN_AGE              12
#define HF_VERSION_EFFECTIVE_SHORT_TERM_MEDIAN_IN_PENALTY 12

#define PER_KB_FEE_QUANTIZATION_DECIMALS        8

#define HASH_OF_HASHES_STEP                     512

#define DEFAULT_TXPOOL_MAX_WEIGHT               648000000ull // 3 days at 300000, in bytes

#define BULLETPROOF_MAX_OUTPUTS                 16

#define CRYPTONOTE_PRUNING_STRIPE_SIZE          4096 // the smaller, the smoother the increase
#define CRYPTONOTE_PRUNING_LOG_STRIPES          3 // the higher, the more space saved
#define CRYPTONOTE_PRUNING_TIP_BLOCKS           5500 // the smaller, the more space saved
//#define CRYPTONOTE_PRUNING_DEBUG_SPOOF_SEED

#define RPC_CREDITS_PER_HASH_SCALE ((float)(1<<24))

// New constants are intended to go here
namespace config
{
  uint64_t const DEFAULT_FEE_ATOMIC_XMR_PER_KB = 500; // Just a placeholder!  Change me!
  uint8_t const FEE_CALCULATION_MAX_RETRIES = 10;
  uint64_t const DEFAULT_DUST_THRESHOLD = ((uint64_t)2000000000); // 2 * pow(10, 9)
  uint64_t const BASE_REWARD_CLAMP_THRESHOLD = ((uint64_t)100000000); // pow(10, 8)

  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0xd1;
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x404f;
  uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x3750;
  uint16_t const P2P_DEFAULT_PORT = 25181;
  uint16_t const RPC_DEFAULT_PORT = 25182;
  uint16_t const ZMQ_RPC_DEFAULT_PORT = 25183;
  boost::uuids::uuid const NETWORK_ID = { {
      0xc5 ,0xf8, 0x71, 0xde , 0xf7, 0x9b , 0x1f, 0x61, 0x17, 0x31, 0x00, 0x82, 0x16, 0xA1, 0xA1, 0x10
    } }; // Bender's nightmare
  std::string const GENESIS_TX = "023c01ff0001d0a7d7a9aa0302dd9522499dbd3d279e10437a0aa54820c40426e1af61230a3f05d24d579582f82101f7af51766389fbe2747d846eac16f497e670656b92f1208576fcec85cb063cc300";
  uint32_t const GENESIS_NONCE = 10000;
  std::string const DEVELOPMENT_WALLET_ADDRESS = "bxdaNPkW77u6KYJuYNDSJpfocTXjVpZ7mMAsoNELySdnbAr8U6aMvnULosC456Kk7NRCAS2Xe7o14NF7bbPKyVta39KPYFia3";
  std::string const MARKETING_WALLET_ADDRESS = "bxdEc4zm1g2ZQZkSwjYThuMJouTSfzL2xJXTC2o4q7Dq17sEcsMdwgRfNuBgg59TPCLJwCj4jJH7rT8bdKjx5p6Z35LJDknWU";
  std::string const AIRTIME_WALLET_ADDRESS = "bxcfouydX4Q2jxw2Thx49bM7tmBiEhP7c8rUoXSVmYxxDpEqqSpBzdRe9WQDkg5LekBtX9W9XinTuG6ttKBtBnpT14KNegFD1"; // view key d6809b482464de15defbbb4127a94118c2ebf77997f45a496863a7266b1406a9
  std::string const COMMUNITY_DEVS_WALLET_ADDRESS = "bxdpg2rivP4g1PzBsm9nq3YXU2V3kDcmogGPxeGvdsup4DBLzdHqW3bEmepzhzS6RPgye1MbiGVbq95UbZxPN19531E9YPMta";
  std::string const COMMUNITY_MODS_WALLET_ADDRESS = "bxdKezUkPt4aci2PqZrEp7gqzkG3e7UC2R7zLn3Bd6dh1NhwRHPuXiB17uejH22dLh2qxj6mVVVZjTvGkbSSthbo2PeM429FW";
  std::string const COMMUNITY_REF_WALLET_ADDRESS = "bxbuTE8eqwtXvQJEoNiDDPXoTExxuLu6igJsEbFuMQ4nBJgSYXHUR9u3PG26UrFZeYJ9d2uyPp28DgUm7SaXwA9u2uirzK4Ef";

  // Hash domain separators
  const char HASH_KEY_BULLETPROOF_EXPONENT[] = "bulletproof";
  const char HASH_KEY_RINGDB[] = "ringdsb";
  const char HASH_KEY_SUBADDRESS[] = "SubAddr";
  const unsigned char HASH_KEY_ENCRYPTED_PAYMENT_ID = 0x8d;
  const unsigned char HASH_KEY_WALLET = 0x8c;
  const unsigned char HASH_KEY_WALLET_CACHE = 0x8d;
  const unsigned char HASH_KEY_RPC_PAYMENT_NONCE = 0x58;
  const unsigned char HASH_KEY_MEMORY = 'k';
  const unsigned char HASH_KEY_MULTISIG[] = {'M', 'u', 'l', 't' , 'i', 's', 'i', 'g', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

  namespace testnet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x9f;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x317a;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x699a;
    uint16_t const P2P_DEFAULT_PORT = 25281;
    uint16_t const RPC_DEFAULT_PORT = 25282;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 25283;
    boost::uuids::uuid const NETWORK_ID = { {
        0xd1 ,0xf8, 0x71, 0xde , 0xf7, 0x9b , 0x1f, 0x61, 0x17, 0x31, 0x00, 0x82, 0x16, 0xA1, 0xA1, 0x10
      } }; // Bender's daydream
    std::string const GENESIS_TX = "023c01ff0001d0a7d7a9aa0302dd9522499dbd3d279e10437a0aa54820c40426e1af61230a3f05d24d579582f82101f7af51766389fbe2747d846eac16f497e670656b92f1208576fcec85cb063cc300";
    uint32_t const GENESIS_NONCE = 10001;
    std::string const DEVELOPMENT_WALLET_ADDRESS = "TbYUtNwz3j9T6rkV9np1g86vKADp9q1VKDhtMkYpFe6g97sp969srp6V8TuEQ8VW33ekPGBfP4jcNHU73s9QHsx91t2fNYDCV";
    std::string const MARKETING_WALLET_ADDRESS = "TbZqBYikYW6NWabAgohg88VLzu4Ch9LUxj8Bf9MwwR6M5ptsW8BwmXU7foHxpKMRF5TMN1SfVHLXf2dw9AbxCgbb2PLSf6NtE";
    std::string const AIRTIME_WALLET_ADDRESS = "TbZm9Nkm7DhTg3UWb226mnSUm97Kw5cFCRyZHSnnixyzg6yXZNrwKz5cqFu1CCeUkcE1u6wHWtcZuck7rYLfEVqV1VQ8bnUQu";
    std::string const COMMUNITY_DEVS_WALLET_ADDRESS = "TbYk7fqjiriMqT4yn64HenECtnpp2MgajZjPSHeegW9XdgZ2d8LCi2XCYYiZ19yzkw1pbg6CGqh5mbzv7ern2zBs1hcKYuNF3";
    std::string const COMMUNITY_MODS_WALLET_ADDRESS = "TbZKz7Pfoir6FsLCeYfxSQPvQDWJvqRGreqfrR4EtEgFjortkugKNFSQuScdgMa8dy7S7ZdKJESkPAeRUcpvY71f2UbsYWtdT";
    std::string const COMMUNITY_REF_WALLET_ADDRESS = "TbaLntZS7swbdAa6hxnyD9ihKQ8vHCbbkaPB5BG65ysCSYfC5yVB96zDYQWmzVyZYS6XVBCBfPxwfCGjtnvuWi8J1Kwj4zBK1";
  }

  namespace stagenet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x99;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x23fa;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x5c1a;
    uint16_t const P2P_DEFAULT_PORT = 25381;
    uint16_t const RPC_DEFAULT_PORT = 25382;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 25383;
    boost::uuids::uuid const NETWORK_ID = { {
        0x70 ,0xf8, 0x71, 0xde , 0xf7, 0x9b , 0x1f, 0x61, 0x17, 0x31, 0x00, 0x82, 0x16, 0xA1, 0xA1, 0x10
      } }; // Bender's daydream
    std::string const GENESIS_TX = "023c01ff0001d0a7d7a9aa0302dd9522499dbd3d279e10437a0aa54820c40426e1af61230a3f05d24d579582f82101f7af51766389fbe2747d846eac16f497e670656b92f1208576fcec85cb063cc300";
    uint32_t const GENESIS_NONCE = 10002;
    std::string const DEVELOPMENT_WALLET_ADDRESS = "SbMYCXHL3KVjWmz8f1aas3ZNCCmPgdEXWUViN6Ms1nmpMUKoWeQGQpDBse1v1w9C7z5pVP89zStbrYHkdu1nPqBf1ALGumYEd";
    std::string const MARKETING_WALLET_ADDRESS = "SbLD4FpSxZXdXZQtPq39gaAefzbCWf1UmUkRuCefRtdPGUzMjYM6p6TcwHoFEH32Ru2PxyfCigFTU7941pbJ8A5F29BqsJY3i";
    std::string const AIRTIME_WALLET_ADDRESS = "SbM84kygYTTPQChpEX4PVTaanFHMhSjJkW6R8JyAgeDURjzKTzMnGmZgdbjcPeRKCz7jEvcjPSnP7hf8bLVqZda11mFgT6EQA";
    std::string const COMMUNITY_DEVS_WALLET_ADDRESS = "SbLs2L3pmo5XX76Uc9MyS798LMkvPfmW5bgA3Ge9wrXJ1P4C9xVwz7wcpCqS5C3bahJataWX34x7CEZoSpoxCppd2KxzsxT9D";
    std::string const COMMUNITY_MODS_WALLET_ADDRESS = "SbLaZaPq1DW5tc4f7YA8PgZdFdkABDWZk17Hk9PujgHKXAK4mHgabrLGPnnRgbybNsZ1fEch6UE9xfB7hJ6TkTqp2TKYnNGGw";
    std::string const COMMUNITY_REF_WALLET_ADDRESS = "SbMXjwpvwQEB441dgnsWViQeXW8gNvNMhiH8b9sBWkZbboxgE73Y9AY3zoX7N2ZWbX5uCGjLjdbXyikbHnF5zDwf2h1XMvaaN";
  }
}

namespace cryptonote
{
  enum network_type : uint8_t
  {
    MAINNET = 0,
    TESTNET,
    STAGENET,
    FAKECHAIN,
    UNDEFINED = 255
  };
  struct config_t
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX;
    uint16_t const P2P_DEFAULT_PORT;
    uint16_t const RPC_DEFAULT_PORT;
    uint16_t const ZMQ_RPC_DEFAULT_PORT;
    boost::uuids::uuid const NETWORK_ID;
    std::string const GENESIS_TX;
    uint32_t const GENESIS_NONCE;
  };
  inline const config_t& get_config(network_type nettype)
  {
    static const config_t mainnet = {
      ::config::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::P2P_DEFAULT_PORT,
      ::config::RPC_DEFAULT_PORT,
      ::config::ZMQ_RPC_DEFAULT_PORT,
      ::config::NETWORK_ID,
      ::config::GENESIS_TX,
      ::config::GENESIS_NONCE
    };
    static const config_t testnet = {
      ::config::testnet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::testnet::P2P_DEFAULT_PORT,
      ::config::testnet::RPC_DEFAULT_PORT,
      ::config::testnet::ZMQ_RPC_DEFAULT_PORT,
      ::config::testnet::NETWORK_ID,
      ::config::testnet::GENESIS_TX,
      ::config::testnet::GENESIS_NONCE
    };
    static const config_t stagenet = {
      ::config::stagenet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::stagenet::P2P_DEFAULT_PORT,
      ::config::stagenet::RPC_DEFAULT_PORT,
      ::config::stagenet::ZMQ_RPC_DEFAULT_PORT,
      ::config::stagenet::NETWORK_ID,
      ::config::stagenet::GENESIS_TX,
      ::config::stagenet::GENESIS_NONCE
    };
    switch (nettype)
    {
      case MAINNET: return mainnet;
      case TESTNET: return testnet;
      case STAGENET: return stagenet;
      case FAKECHAIN: return mainnet;
      default: throw std::runtime_error("Invalid network type");
    }
  };
}

/*
TbYUtNwz3j9T6rkV9np1g86vKADp9q1VKDhtMkYpFe6g97sp969srp6V8TuEQ8VW33ekPGBfP4jcNHU73s9QHsx91t2fNYDCV
never fossil wedge hashing cavernous dagger tribal foxes itself asylum piloted puddle runway welders gemstone sarcasm gimmick metro wagtail cogs ammo never stunning tilt tribal
TbZqBYikYW6NWabAgohg88VLzu4Ch9LUxj8Bf9MwwR6M5ptsW8BwmXU7foHxpKMRF5TMN1SfVHLXf2dw9AbxCgbb2PLSf6NtE
pistons rhino muddy roles dilute uneven hijack southern kiosk syndrome problems pamphlet cabin terminal nowhere voted space beware erected wetsuit total lectures yahoo ajar erected
TbZm9Nkm7DhTg3UWb226mnSUm97Kw5cFCRyZHSnnixyzg6yXZNrwKz5cqFu1CCeUkcE1u6wHWtcZuck7rYLfEVqV1VQ8bnUQu
visited sorry etched lottery cowl uphill sowed erected yoyo launching bakery trolling possible fonts motherly poaching enjoy pixels hence athlete boldly upbeat elite emails elite
TbYk7fqjiriMqT4yn64HenECtnpp2MgajZjPSHeegW9XdgZ2d8LCi2XCYYiZ19yzkw1pbg6CGqh5mbzv7ern2zBs1hcKYuNF3
sunken furnished kidneys tossed suffice acoustic uptight giant victim stick distance stunning pixels hectare apex ought ankle slug mowing tobacco poetry imbalance biscuit cider acoustic
TbZKz7Pfoir6FsLCeYfxSQPvQDWJvqRGreqfrR4EtEgFjortkugKNFSQuScdgMa8dy7S7ZdKJESkPAeRUcpvY71f2UbsYWtdT
voted wizard cistern lush geometry younger buying civilian extra acquire answers fetches tubes dagger himself oscar coal merger duke putty unusual goldfish trolling vary oscar
TbaLntZS7swbdAa6hxnyD9ihKQ8vHCbbkaPB5BG65ysCSYfC5yVB96zDYQWmzVyZYS6XVBCBfPxwfCGjtnvuWi8J1Kwj4zBK1
lexicon fainted inline wedge nineteen goodbye cool voice poker tinted poverty avatar kennel wayside yacht dusted happens hyper rhino invoke sleepless kitchens basin citadel happens

SbMYCXHL3KVjWmz8f1aas3ZNCCmPgdEXWUViN6Ms1nmpMUKoWeQGQpDBse1v1w9C7z5pVP89zStbrYHkdu1nPqBf1ALGumYEd
lyrics inmate alumni syringe july noted tomorrow echo owner ocean frying friendly sowed dogs tulips toilet echo dozen tinted jeers cogs axes velvet website noted
SbLD4FpSxZXdXZQtPq39gaAefzbCWf1UmUkRuCefRtdPGUzMjYM6p6TcwHoFEH32Ru2PxyfCigFTU7941pbJ8A5F29BqsJY3i
wrong seventh hedgehog gusts waffle unopened mops gather vary yoga woven noises gossip kettle psychic vigilant vibrate buzzer vitals huge faxed double hawk hesitate noises
SbM84kygYTTPQChpEX4PVTaanFHMhSjJkW6R8JyAgeDURjzKTzMnGmZgdbjcPeRKCz7jEvcjPSnP7hf8bLVqZda11mFgT6EQA
gnaw nasty input ceiling himself rhino alpine vein wiring acidic exquisite grunt jackets else five mohawk leopard cool meant unwind dubbed aimless strained tell aimless
SbLs2L3pmo5XX76Uc9MyS798LMkvPfmW5bgA3Ge9wrXJ1P4C9xVwz7wcpCqS5C3bahJataWX34x7CEZoSpoxCppd2KxzsxT9D
language daytime kangaroo january liquid observant exquisite vector maximum anybody network ridges oust nurse himself dauntless eagle talent unlikely waveform drinks relic guys hashing guys
SbLaZaPq1DW5tc4f7YA8PgZdFdkABDWZk17Hk9PujgHKXAK4mHgabrLGPnnRgbybNsZ1fEch6UE9xfB7hJ6TkTqp2TKYnNGGw
quote hence rhythm oilfield cottage total omega comb zodiac sixteen irritate rigid tolerant gumball smash gotten loyal gigantic enlist imbalance cuisine unzip fazed fugitive gigantic
SbMXjwpvwQEB441dgnsWViQeXW8gNvNMhiH8b9sBWkZbboxgE73Y9AY3zoX7N2ZWbX5uCGjLjdbXyikbHnF5zDwf2h1XMvaaN
utility ungainly business cinema toolbox hobby ruffled scuba foamy habitat rumble until nail mews nineteen onboard drying hubcaps timber wetsuit reinvest dozen initiate jeopardy utility
*/
