auto make_box( c_base_player *player, std::int32_t &x, std::int32_t &y, std::int32_t &w, std::int32_t &h ) {
  const auto center = player->world_space_center();
  if( !center ) return false;
 
  const auto center_screen = center.to_screen();
  if( !center_screen ) return false;
 
  const auto model = player->get_model();
  if( !model ) return false;
 
  const auto studio = base::interfaces::model_info->get_studio_model( model );
  if( !studio ) return false;
 
  const auto set = studio->hitbox_set( player->m_nHitboxSet() );
  if( !set ) return false;
 
  auto x0 = center_screen.x, x1 = center_screen.x,
       y0 = center_screen.y, y1 = center_screen.y;
 
  for( auto i = set->num_hitboxes; i--; ) {
    for( const auto &point: player->get_hitbox( i )->get_points() ) {
      if( !point ) continue;
 
      const auto point_screen = point.to_screen();
      if( !point_screen ) continue;
 
      x0 = std::min( x0, point_screen.x );
      x1 = std::max( x1, point_screen.x );
 
      y0 = std::min( y0, point_screen.y );
      y1 = std::max( y1, point_screen.y );
    }
  }
 
  x = std::int32_t( std::round( x0 ) );
  y = std::int32_t( std::round( y0 ) );
 
  w = std::int32_t( std::round( x1 - x0 ) );
  h = std::int32_t( std::round( y1 - y0 ) );
 
  return true;
}
