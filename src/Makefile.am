bin_PROGRAMS = atlc create_bmp_for_rect_in_rect \
create_any_bitmap \
create_bmp_for_circ_in_circ create_bmp_for_rect_cen_in_rect \
create_bmp_for_circ_in_rect create_bmp_for_rect_in_circ \
readbin create_bmp_for_symmetrical_stripline \
design_coupler create_bmp_for_stripline_coupler \
create_bmp_for_microstrip_coupler \
find_optimal_dimensions_for_microstrip_coupler \
create_bmp_for_rect_cen_in_rect_coupler 

atlc_SOURCES = atlc.c read_bitmap_file_headers.c \
update_voltage_array.c \
check_for_boundaries.c \
memory.c setup_arrays.c \
finite_difference_single_threaded.c \
finite_difference_multi_threaded.c \
usage_atlc.c \
check_for_shorts.c bmp.h definitions.h Erdata.h \
find_energy_per_metre.c \
set_oddity_from_Greens_paper.c \
get_file_pointer_with_right_filename.c \
find_maximum_values.c calculate_colour_data.c find_electric_fields.c \
get_options.c exit_with_msg_and_exit_code.c do_fd_calculation.c \
swap_conductor_voltages.c print_copyright.c \
print_data_for_directional_couplers.c \
print_data_for_two_conductor_lines.c \
set_data_to_sensible_starting_values.c \
write_fields_for_two_conductor_lines.c \
write_fields_for_directional_couplers.c \
exit_codes.h definitions.h

atlc_CPPFLAGS = -DNEED_MPI_CODE @PTHREAD_CFLAGS@
atlc_LDADD = @PTHREAD_LIBS@ @LIBS@ 


create_bmp_for_rect_in_rect_SOURCES = create_bmp_for_rect_in_rect.c \
usage_create_bmp_for_rect_in_rect.c write_bitmap.c \
get_Er1_and_Er2_colours.c  \
convert_create_bmp_for_rect_in_rect_dimensions_to_integers.c \
memory.c write_bitmap_out.c  \
align_bitmap_image.c fill_rect_in_rect.c \
check_parameters_of_create_bmp_for_rect_in_rect.c \
check_error.c get_options.c definitions.h \
exit_with_msg_and_exit_code.c print_copyright.c \
exit_codes.h definitions.h

create_bmp_for_rect_in_rect_LDADD = @LIBS@ 

create_any_bitmap_SOURCES = \
create_any_bitmap.c \
exit_with_msg_and_exit_code.c \
definitions.h \
exit_codes.h \
usage_create_any_bitmap.c

create_bmp_for_rect_cen_in_rect_coupler_SOURCES = \
create_bmp_for_rect_cen_in_rect_coupler.c \
usage_create_bmp_for_rect_cen_in_rect_coupler.c \
get_options.c definitions.h memory.c \
write_bitmap_out.c  \
align_bitmap_image.c check_error.c exit_with_msg_and_exit_code.c \
print_copyright.c \
exit_codes.h definitions.h


create_bmp_for_rect_cen_in_rect_SOURCES = create_bmp_for_rect_cen_in_rect.c \
usage_create_bmp_for_rect_cen_in_rect.c \
write_bitmap.c \
get_Er1_and_Er2_colours.c \
convert_create_bmp_for_rect_in_rect_dimensions_to_integers.c \
memory.c write_bitmap_out.c  \
align_bitmap_image.c \
fill_rect_in_rect.c check_parameters_of_create_bmp_for_rect_in_rect.c \
check_error.c get_options.c definitions.h exit_with_msg_and_exit_code.c \
print_copyright.c Erdata.h exit_codes.h
create_bmp_for_rect_cen_in_rect_LDADD = @LIBS@ 
 
create_bmp_for_microstrip_coupler_SOURCES = \
usage_create_bmp_for_microstrip_coupler.c \
create_bmp_for_microstrip_coupler.c get_Er1_and_Er2_colours.c \
convert_create_bmp_for_coupled_microstrip_dimensions_to_integers.c \
print_copyright.c  \
write_bitmap_out.c memory.c \
get_options.c check_parameters_of_create_bmp_for_microstrip_coupler.c \
write_bitmap.c align_bitmap_image.c \
fill_image_vector_for_create_bmp_for_microstrip_coupler.c \
check_error.c exit_with_msg_and_exit_code.c \
Erdata.h definitions.h exit_codes.h
create_bmp_for_microstrip_coupler_LDADD = @LIBS@ 

create_bmp_for_circ_in_circ_SOURCES = create_bmp_for_circ_in_circ.c \
usage_create_bmp_for_circ_in_circ.c write_bitmap.c \
get_Er1_and_Er2_colours.c \
convert_create_bmp_for_circ_in_circ_dimensions_to_integers.c \
memory.c write_bitmap_out.c  \
align_bitmap_image.c fill_circ_in_circ.c \
check_parameters_of_create_bmp_for_circ_in_circ.c \
check_error.c get_options.c definitions.h exit_with_msg_and_exit_code.c \
print_copyright.c Erdata.h
create_bmp_for_circ_in_circ_LDADD = @LIBS@ 

create_bmp_for_circ_in_rect_SOURCES = create_bmp_for_circ_in_rect.c \
convert_create_bmp_for_circ_in_rect_dimensions_to_integers.c \
usage_create_bmp_for_circ_in_rect.c write_bitmap.c \
get_Er1_and_Er2_colours.c \
check_parameters_of_create_bmp_for_circ_in_rect.c \
memory.c write_bitmap_out.c  \
align_bitmap_image.c fill_circ_in_rect.c  \
check_error.c get_options.c definitions.h exit_with_msg_and_exit_code.c \
print_copyright.c Erdata.h exit_codes.h
create_bmp_for_circ_in_rect_LDADD = @LIBS@ 

create_bmp_for_rect_in_circ_SOURCES = create_bmp_for_rect_in_circ.c \
usage_create_bmp_for_rect_in_circ.c write_bitmap.c \
get_Er1_and_Er2_colours.c \
convert_create_bmp_for_rect_in_circ_dimensions_to_integers.c \
memory.c write_bitmap_out.c  \
align_bitmap_image.c fill_rect_in_circ.c check_parameters_of_create_bmp_for_rect_in_circ.c \
check_error.c get_options.c definitions.h exit_with_msg_and_exit_code.c \
print_copyright.c Erdata.h

readbin_SOURCES = \
readbin.c \
get_options.c exit_with_msg_and_exit_code.c print_copyright.c \
usage_readbin.c byteswap.c \
memory.c 
readbin_LDADD = @LIBS@ 

create_bmp_for_symmetrical_stripline_SOURCES = \
create_bmp_for_symmetrical_stripline.c \
fill_image_vector_for_create_bmp_for_symmetrical_stripline.c \
usage_create_bmp_for_symmetrical_stripline.c memory.c  write_bitmap_out.c \
align_bitmap_image.c  \
calculate_impedance_for_create_bmp_for_symmetrical_stripline.c \
elliptic_integral.c get_options.c definitions.h exit_with_msg_and_exit_code.c \
print_copyright.c
create_bmp_for_symmetrical_stripline_LDADD = @LIBS@ 

create_bmp_for_stripline_coupler_SOURCES = \
create_bmp_for_stripline_coupler.c usage_create_bmp_for_stripline_coupler.c \
calculate_Zodd_and_Zeven.c get_options.c definitions.h \
calculate_integer_values.c write_bitmap.c \
memory.c write_bitmap_out.c  \
align_bitmap_image.c fill_make_coupler.c \
check_error.c exit_with_msg_and_exit_code.c \
get_Er1_and_Er2_colours.c print_copyright.c  \
gsl_types.h \
gsl_definitions.h \
gsl_sf_ellint_Kcomp.c
create_bmp_for_stripline_coupler_LDADD = @LIBS@ 
create_bmp_for_stripline_coupler_CFLAGS = @CFLAGS@ 

design_coupler_SOURCES = design_coupler.c usage_design_coupler.c \
get_options.c print_copyright.c calculate_Zodd_and_Zeven.c \
give_examples_of_using_design_coupler.c exit_with_msg_and_exit_code.c \
gsl_types.h \
gsl_definitions.h \
gsl_sf_ellint_Kcomp.c
design_coupler_LDADD = @LIBS@ 
design_coupler_CFLAGS = @CFLAGS@ 

find_optimal_dimensions_for_microstrip_coupler_SOURCES = \
find_optimal_dimensions_for_microstrip_coupler.c \
exit_with_msg_and_exit_code.c \
usage_find_optimal_dimensions_for_microstrip_coupler.c \
print_copyright.c get_options.c \
memory.c \
check_parameters_for_find_optimal_dimensions_for_microstrip_coupler.c 
find_optimal_dimensions_for_microstrip_coupler_LDADD = @LIBS@

EXTRA_DIST = finite_difference_mpi.c

