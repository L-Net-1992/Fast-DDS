#include <openssl/evp.h>
#include <openssl/engine.h>
#include <openssl/rand.h>
#include <openssl/err.h>

namespace eprosima {
namespace fastdds {
namespace rtps {
namespace security {

class OpenSSLInit
{
public:

    OpenSSLInit()
    {
#if OPENSSL_VERSION_NUMBER < 0x10100000L
        OpenSSL_add_all_algorithms();
#endif // if OPENSSL_VERSION_NUMBER < 0x10100000L
    }

    ~OpenSSLInit()
    {
#if OPENSSL_VERSION_NUMBER < 0x10000000L
        ERR_remove_state(0);
        ENGINE_cleanup();
#elif OPENSSL_VERSION_NUMBER < 0x10100000L
        ERR_remove_thread_state(NULL);
        ENGINE_cleanup();
#endif // if OPENSSL_VERSION_NUMBER < 0x10000000L
        RAND_cleanup();
        CRYPTO_cleanup_all_ex_data();
        ERR_free_strings();
        EVP_cleanup();
    }

};

} // namespace security
} // namespace rtps
} // namespace fastdds
} // namespace eprosima
