Pod::Spec.new do |s|
	s.name                = "Z"
	s.module_name         = "Z"
	s.version             = "0.1.0"
	s.summary             = "Header-only multi-platform base API written in C/C++"
	s.homepage            = "https://github.com/redcode/Z"
	s.license             = {:type => 'LGPLv3', :file => 'COPYING.LESSER'}
	s.authors             = "Manuel Sainz de Baranda y Goñi"
	s.source              = {:git => "https://github.com/redcode/Z.git", :tag => s.version.to_s}
	s.requires_arc        = false
	s.header_dir          = "Z"
	s.header_mappings_dir = "Z"
	s.libraries           = 'c++'
	s.source_files        = '../../API/**/*.h'
	s.xcconfig            = {'LIBRARY_SEARCH_PATHS' => '$(PODS_ROOT)/API'}
	s.preserve_paths      = 'Z/**/*{.h,.hpp,.inl}'
	s.public_header_files = 'API/Z/**/*.h'
end
