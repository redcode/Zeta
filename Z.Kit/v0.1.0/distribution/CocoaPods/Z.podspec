Pod::Spec.new do |s|
	s.name                = "Z"
	s.module_name         = "Z"
	s.version             = "0.1.0"
	s.summary             = "Header-only multi-platform base API written in C/C++"
	s.homepage            = "https://github.com/redcode/Z"
	s.license             = {:type => 'MIT', :file => 'copying.txt'}
	s.authors             = "Manuel Sainz de Baranda y Goñi"
	s.source              = {:git => "https://github.com/redcode/Z.git", :tag => s.version.to_s}
	s.requires_arc        = false
	s.header_dir          = "glm"
	s.header_mappings_dir = "glm"
	s.libraries           = 'c++'
	s.source_files        = 'glm/**/*{.h,.hpp}'
	s.xcconfig            = {'LIBRARY_SEARCH_PATHS' => '$(PODS_ROOT)/glm'}
	s.preserve_paths      = 'glm/**/*{.h,.hpp,.inl}'
	s.public_header_files = 'Z.Kit/v1.0/API/C/Z/**/*.h', 'Z.Kit/v1.0/API/C++/Z/**/*.h', 
end
