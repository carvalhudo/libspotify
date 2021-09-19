/**
 * @file
 *
 * @brief Api main class implementation.
 */
#include "api.h"

#include "private/api_private.h"

namespace espotifai_api {

using std::exception;
using std::make_shared;
using std::shared_ptr;
using std::string;

Api::Api(const shared_ptr<Authenticator>& auth,
         const shared_ptr<Searcher>& searcher,
         const shared_ptr<PlaylistMgr>& mgr)
    : private_{make_shared<ApiPrivate>(auth, searcher, mgr)} {}

void Api::Auth(AccessListener& listener, const string& client_id,
               const string& client_secret) const {
  private_->Auth(listener, client_id, client_secret);
}

void Api::Search(SearchListener& listener, const string& token,
                 const string& name) const {
  private_->Search(listener, token, name);
}

void Api::CreatePlaylist(PlaylistListener& listener, const string& name) const {
  private_->CreatePlaylist(listener, name);
}

void Api::AddMusicToPlaylist(AddMusicPlaylistListener& listener,
                             const MusicInfo& music,
                             const string& playlist) const {
  private_->AddMusicToPlaylist(listener, music, playlist);
}

void Api::ListPlaylistMusics(PlaylistListener& listener,
                             const string& playlist_name) const {
  private_->ListPlaylistMusics(listener, playlist_name);
}

void Api::GetPlaylists(PlaylistListener& listener) const {
  private_->GetPlaylists(listener);
}

}  // namespace espotifai_api
