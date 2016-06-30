#ifndef BITCOIN_TEST_TEST_BITCOIN_H
#define BITCOIN_TEST_TEST_BITCOIN_H

#include "chainparamsbase.h"
#include "txdb.h"

#include <boost/filesystem.hpp>
#include <boost/thread.hpp>

/** Basic testing setup.
 * This just configures logging and chain parameters.
 */
struct BasicTestingSetup {
    BasicTestingSetup();
    ~BasicTestingSetup();
};

/** Testing setup that configures a complete environment.
 * Included are data directory, coins database, script check threads
 * and wallet (if enabled) setup.
 */
struct TestingSetup: public BasicTestingSetup {
    CCoinsViewDB *pcoinsdbview;
    boost::filesystem::path pathTemp;
    boost::thread_group threadGroup;

    TestingSetup();
    ~TestingSetup();
};

/** Wallet setup that configures a complete environment.
 * Included are data directory, coins database, script check threads
 * and wallet with 5 unused keys.
 */
struct WalletSetup: public BasicTestingSetup {
	boost::filesystem::path pathTemp;

	WalletSetup(CBaseChainParams::Network network = CBaseChainParams::MAIN);
	~WalletSetup();
};
#endif
