/**
 * \file
 * \brief Api main class definition.
 */
#ifndef API_H_
#define API_H_

#include <memory>
#include <string>

#include "access_listener.h"
#include "add_music_playlist_listener.h"
#include "playlist_listener.h"
#include "search_music_listener.h"
#include "types.h"

namespace espotifai_api {

class ApiPrivate;
class MusicSearcher;
class PlaylistMgr;
class SpotifyAuth;

/**
 * \class Api.
 *
 * \brief This class implements the main functionalities of espotifai API.
 */
class Api {
 public:
  /**
   * \brief Constructor.
   * \param auth Spotify authenticator instance.
   * \param searcher Spotify music searcher.
   * \param mgr Playlist manager.
   */
  Api(const std::shared_ptr<SpotifyAuth>& auth = nullptr,
      const std::shared_ptr<MusicSearcher>& searcher = nullptr,
      const std::shared_ptr<PlaylistMgr>& mgr = nullptr);

  /**
   * \brief Authenticate a user using the spotify API.
   * \param listener Event listener.
   * \param client_id Client's ID.
   * \param client_secret Client's secret.
   */
  void RequestAccess(AccessListener& listener, const std::string& client_id,
                     const std::string& client_secret) const;

  /**
   * \brief Search for a music in the spotify platform.
   * \param listener Event listener.
   * \param token Access token.
   * \param name Name of the music.
   */
  void SearchMusic(SearchMusicListener& listener, const std::string& token,
                   const std::string& name) const;

  /**
   * \brief Create an offline spotify playlist.
   * \param listener Event listener.
   * \param name Name of the playlist.
   * \param owner Owner of the playlist.
   */
  void CreatePlaylist(PlaylistListener& listener, const std::string& name,
                      const std::string& owner) const;

  /**
   * \brief Add a music into an existent playlist.
   * \param listener Event listener.
   * \param music Informations of the music.
   * \param playlist Name of the playlist.
   */
  void AddMusicToPlaylist(AddMusicPlaylistListener& listener,
                          const MusicInfo& music,
                          const std::string& playlist) const;

  /**
   * \brief List the musics for a given playlist.
   * \param listener Event listener.
   * \param playlist_name Name of the playlist.
   */
  void ListPlaylistMusics(PlaylistListener& listener,
                          const std::string& playlist_name) const;

  /**
   * \brief Get all playlists registered on database.
   * \param listener Event listener.
   */
  void GetPlaylists(PlaylistListener& listener) const;

 private:
  // TODO: make it a unique_ptr
  std::shared_ptr<ApiPrivate> private_;  //!< API private.
};

}  // namespace espotifai_api

#endif  // API_H_
